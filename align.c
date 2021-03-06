/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 00:30:19 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 05:32:32 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_len(t_align *al)
{
	al->syml = nb_len(al->syml);
	al->min = nb_len(al->min);
	al->maj = nb_len(al->maj);
	al->size = (al->is) ? al->maj + al->min + 4 : nb_len(al->size);
}

void	compare(t_file *file, t_align *al)
{
	struct passwd	*p;
	struct group	*g;

	p = getpwuid(file->stat->st_uid);
	g = getgrgid(file->stat->st_gid);
	if (S_ISBLK(file->stat->st_mode) || S_ISCHR(file->stat->st_mode))
	{
		al->is = 1;
		if (al->min < (int)MINOR(file->stat->st_rdev))
			al->min = MINOR(file->stat->st_rdev);
		if (al->maj < (int)MAJOR(file->stat->st_rdev))
			al->maj = MAJOR(file->stat->st_rdev);
	}
	if (al->syml < file->stat->st_nlink)
		al->syml = file->stat->st_nlink;
	if (al->size < file->stat->st_size)
		al->size = file->stat->st_size;
	if (al->usr < (int)ft_strlen(p ? p->pw_name : ft_itoa(file->stat->st_uid)))
		al->usr = ft_strlen(p ? p->pw_name : ft_itoa(file->stat->st_uid));
	if (al->grp < (int)ft_strlen(g ? g->gr_name : ft_itoa(file->stat->st_gid)))
		al->grp = ft_strlen(g ? g->gr_name : ft_itoa(file->stat->st_gid));
}

int		max_list(t_list *list, t_align *al, t_options *opt)
{
	int				tot_size;

	tot_size = 0;
	while (list)
	{
		if (L(list)->name[0] != '.' || opt->a)
		{
			compare(L(list), al);
			tot_size += L(list)->stat->st_blocks;
		}
		list = list->next;
	}
	get_len(al);
	return (tot_size);
}
