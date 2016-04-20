/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 23:32:39 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 01:39:46 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	affect_option(t_options *opt, char c)
{
	if (c == 'l' || c == 'r' || c == 'a' || c == 't' || c == 'R' || c == '1')
	{
		opt->l += (c == 'l') ? 1 : 0;
		opt->r += (c == 'r') ? 1 : 0;
		opt->a += (c == 'a') ? 1 : 0;
		opt->t += (c == 't') ? 1 : 0;
		opt->gr += (c == 'R') ? 1 : 0;
		return ;
	}
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		ft_putendl_fd("usage : ls [Raltr1]", 2);
		exit(2);
	}
}

void	build_list(char *str, t_list **rep_list, t_list **fil_list)
{
	t_file *file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		exit(2);
	if (!(file->stat = (struct stat *)malloc(sizeof(struct stat))))
		exit(2);
	if (stat(str, file->stat) == -1)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		free(file->stat);
		free(file);
	}
	else
	{
		file->name = ft_strdup(str);
		if (S_ISDIR(file->stat->st_mode))
		{
			file->path = add_path(".", file->name);
			ft_push_back(rep_list, file, 0);
		}
		else
			ft_push_back(fil_list, file, 0);
	}
}

int		parser(char **tab_arg, t_options *opt, t_list **rep_l, t_list **fil_l)
{
	int			i;
	int			j;
	int			nb_operand;

	nb_operand = 0;
	i = 1;
	while (tab_arg[i] && *tab_arg[i] == '-' && ft_strcmp(tab_arg[i], "--")\
			&& ft_strlen(tab_arg[i]) > 1)
	{
		j = 0;
		while (tab_arg[i][++j])
			affect_option(opt, tab_arg[i][j]);
		i++;
	}
	(tab_arg[i] && !(ft_strncmp(tab_arg[i], "--", 2))) ? i++ : 0;
	while (tab_arg[i])
	{
		build_list(tab_arg[i], rep_l, fil_l);
		i++;
		nb_operand++;
	}
	return (nb_operand);
}
