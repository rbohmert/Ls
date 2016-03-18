/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:16:41 by rbohmert          #+#    #+#             */
/*   Updated: 2016/02/18 23:52:28 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char 	*add_path(char *path, char *rep)
{
	char *res;

	if (!(res = (char *)malloc(ft_strlen(rep) + ft_strlen(path) + 3)))
		return (NULL);
	ft_strcpy(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, rep);
	return (res);
}

void	stock(t_list **list, t_list **list_dir, DIR *rep, char *str)
{	
	struct	dirent	*file = NULL;
	struct	stat	*buf;
	char			*path_name;
	t_file			*file_s;

	while ((file = readdir(rep)))
	{
		if (!(buf = (struct stat *)malloc(sizeof(struct stat))) || !(file_s = (t_file *)malloc(sizeof(t_file))))
			return;
		path_name = add_path(str, file->d_name);
		lstat(path_name, buf);
		file_s->stat = buf;
		file_s->name = ft_strdup(file->d_name);
		ft_push_back(list, file_s, 0);
		if (S_ISDIR(buf->st_mode) && ft_strcmp(file->d_name, ".") != 0 && ft_strcmp(file->d_name, "..") != 0)
			ft_push_back(list_dir, ft_strdup(path_name), 0);
		free(path_name);
	}
}

void	free_list(t_list *list, int flag)
{
	t_list *tmp;
	
	if (!list)
		return;
	tmp = list;
	while (tmp)
	{
		if (flag)
		{
			free(((t_file *)tmp->content)->name);
			free(((t_file *)tmp->content)->stat);
		}
		free(tmp->content);
		tmp = tmp->next;
	}
	tmp = list;
	list = list->next;
	while (list)
	{
		free(tmp);
		tmp = list;
		list = list->next;
	}
	free(tmp);
}


int					ft_ls(char *str, t_options *opt)
{
	DIR				*rep = NULL;
	t_list			*list = NULL;
	t_list			*list_dir = NULL; 
	t_list			*tmp;

	if (!(rep = opendir(str)))
	{
		perror("Error ");
		exit(2);
	}
	stock(&list, &list_dir, rep, str);
	trier(&list_dir, 1);
	opt->r ? ft_list_reverse(&list) : 0;
	print(list, opt);
	if (closedir(rep) == -1)
	{
		perror("Error ");
		exit(2);
	}
	tmp = list_dir;
	while (tmp && opt->R)
	{
		if (!(*(char*)tmp->content == '.') || opt->a)
		{
			ft_putstr(tmp->content);
			ft_putstr(":\n");
			ft_ls(tmp->content, opt);
		}
		tmp = tmp->next;
	}
	free_list(list, 1);
	free_list(list_dir, 0);
	return (1);
}

int main (int ac, char **av)
{
	t_options	opt;
	t_list		*rep_list = NULL;
	t_list		*fil_list = NULL;
	int			nb_operand;

	init_opt(&opt);
	nb_operand = parser(av, &opt, &rep_list, &fil_list);
	if (nb_operand == 0)
		ft_ls(".", &opt);
	if (nb_operand == 1)
	{
		if (!fil_list && rep_list)
			ft_ls(rep_list->content, &opt);
		if (fil_list && !rep_list)
			ft_putendl(((t_file *)fil_list->content)->name);
	}
	if (nb_operand > 1)
	{
		print(fil_list, &opt);
		while (rep_list)
		{
			ft_putstr("\n");
			ft_putstr(rep_list->content);
			ft_putendl(":");
			ft_ls(rep_list->content, &opt);
			rep_list = rep_list->next;
		}
	}
	free_list(fil_list, 1);
	free_list(rep_list, 0);
	return 0;
}
