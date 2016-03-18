/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 23:32:39 by rbohmert          #+#    #+#             */
/*   Updated: 2016/03/18 22:16:56 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void init_opt(t_options *opt)
{
	opt->l = 0;
	opt->r = 0;
	opt->R = 0;
	opt->t = 0;
	opt->a = 0;
}

void	affect_option(t_options *opt, char c)
{
	if (c == 'l' || c == 'r' || c == 'a' || c == 't' || c == 'R')
	{
		opt->l += (c == 'l') ? 1 : 0;
		opt->r += (c == 'r') ? 1 : 0;
		opt->a += (c == 'a') ? 1 : 0;
		opt->t += (c == 't') ? 1 : 0;
		opt->R += (c == 'R') ? 1 : 0;
		return;
	}
	else
	{
		printf("ft_ls: illegal option -- %c", c);
		exit(2);
	}
}

int		parser(char **tab_arg, t_options *opt, t_list **rep_list, t_list **fil_list)
{
	struct stat	*buf;
	int 		i;
	int			j;
	int			nb_operand;
	t_file		*file;

	nb_operand = 0;
	if(!(buf = (struct stat *)malloc(sizeof(struct stat))) || !(file = (t_file *)malloc(sizeof(t_file))))
		exit (2);
	i = 1;
	while (tab_arg[i] && *tab_arg[i] == '-' && ft_strlen(tab_arg[i]) > 1)
	{
		j = 0;
		while (tab_arg[i][++j])
			affect_option(opt, tab_arg[i][j]);
		i++;
	}
	while (tab_arg[i])
	{
		if (lstat(tab_arg[i], buf) == -1)
			printf("ft_ls: %s: No such file of directory\n", tab_arg[i]);
		else
		{
			if (S_ISDIR(buf->st_mode))
				ft_push_back(rep_list, ft_strdup(tab_arg[i]), 0);
			else
			{
				file->stat = buf;
				file->name = ft_strdup(tab_arg[i]);
				ft_push_back(fil_list, file, 0);
			}
		}
		i++;
		nb_operand++;
	}
	return (nb_operand);
}
