/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:16:41 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 01:40:55 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stock(t_list **list, DIR *rep, char *str, t_options *opt)
{
	struct dirent	*file;
	struct stat		*buf;
	char			*path_name;
	t_file			*file_s;

	file = NULL;
	*list = NULL;
	while ((file = readdir(rep)))
	{
		if (!(buf = (struct stat *)malloc(sizeof(struct stat)))\
			|| !(file_s = (t_file *)malloc(sizeof(t_file))))
			return ;
		path_name = add_path(str, file->d_name);
		lstat(path_name, buf);
		file_s->stat = buf;
		file_s->name = ft_strdup(file->d_name);
		file_s->path = path_name;
		ft_push_back(list, file_s, 0);
	}
	trier(list, 2);
	(opt->t) ? trier(list, 3) : 0;
	(opt->r) ? ft_list_reverse(list) : 0;
	print(list, opt, 1);
}

void	ls_r(t_list *list, char *str, t_options *opt)
{
	t_list	*tmp;
	char	*path_name;

	tmp = list;
	while (tmp)
	{
		if ((S_ISDIR(L(tmp)->stat->st_mode) && ft_strcmp(L(tmp)->name, ".")\
			!= 0 && ft_strcmp(L(tmp)->name, "..") != 0) && (!(*(L(tmp)->name)\
			== '.') || opt->a))
		{
			path_name = add_path(str, L(tmp)->name);
			ft_putstr("\n");
			ft_putstr(path_name);
			ft_putstr(":\n");
			ft_ls(path_name, opt);
			free(path_name);
		}
		tmp = tmp->next;
	}
}

int		ft_ls(char *str, t_options *opt)
{
	DIR				*rep;
	t_list			*list;

	rep = NULL;
	list = NULL;
	if (!(rep = opendir(str)))
	{
		ft_putstr("ls: ");
		ft_putstr(ft_strrchr(str, '/') ? ft_strrchr(str, '/') + 1 : str);
		ft_putstr(": ");
		perror("");
	}
	else
	{
		stock(&list, rep, str, opt);
		if (closedir(rep) == -1)
		{
			perror("Error ");
			exit(2);
		}
	}
	if (list && opt->gr)
		ls_r(list, str, opt);
	free_list(list, 1);
	return (1);
}

void	multi_file(t_list *rep_list, t_list *fil_list, t_options *opt)
{
	(fil_list) ? print(&fil_list, opt, 0) : 0;
	(fil_list && rep_list) ? write(1, "\n", 1) : 0;
	while (rep_list)
	{
		ft_putstr(L(rep_list)->name);
		ft_putendl(":");
		ft_ls(L(rep_list)->name, opt);
		(rep_list->next) ? ft_putstr("\n") : 0;
		rep_list = rep_list->next;
	}
}

int		main(int ac, char **av)
{
	t_options	opt;
	t_list		*rep_list;
	t_list		*fil_list;
	int			nb_operand;

	rep_list = NULL;
	fil_list = NULL;
	ac = 1;
	ft_bzero(&opt, sizeof(t_options));
	nb_operand = parser(av, &opt, &rep_list, &fil_list);
	if (nb_operand == 0)
		ft_ls(".", &opt);
	if (nb_operand == 1)
		(!fil_list && rep_list) ? ft_ls(L(rep_list)->name, &opt)\
		: print(&fil_list, &opt, 0);
	if (nb_operand > 1)
		multi_file(rep_list, fil_list, &opt);
	(fil_list) ? free_list(fil_list, 0) : 0;
	(rep_list) ? free_list(rep_list, 0) : 0;
	return (0);
}
