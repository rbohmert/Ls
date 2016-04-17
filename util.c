/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 23:44:11 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/15 23:23:44 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_list(t_list *list, int flag)
{
	t_list *tmp;

	if (!list)
		return ;
	tmp = list;
	while (tmp)
	{
		if (flag)
			free(((t_file *)tmp->content)->path);
		free(((t_file *)tmp->content)->name);
		free(((t_file *)tmp->content)->stat);
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

char	*add_path(char *path, char *rep)
{
	char *res;

	if (!(res = (char *)malloc(ft_strlen(rep) + ft_strlen(path) + 3)))
		return (NULL);
	ft_strcpy(res, path);
	ft_strcat(res, "/");
	ft_strcat(res, rep);
	return (res);
}

void	max_list2(t_file *file, int *max0, int *max1)
{
	int i;
	int tmp;

	i = 0;
	tmp = file->stat->st_nlink;
	while ((tmp = tmp / 10))
		i++;
	*max0 = *max0 < i ? i : *max0;
	i = 0;
	tmp = file->stat->st_size;
	while ((tmp = tmp / 10))
		i++;
	*max1 = *max1 < i ? i : *max1;
}

int		max_list(t_list *list, int max[4], t_options *opt)
{
	int				tot_size;
	struct passwd	*passwd;
	struct group	*grp;

	tot_size = 0;
	while (list)
	{
		if (L(list)->name[0] != '.' || opt->a)
		{
			passwd = getpwuid(L(list)->stat->st_uid);
			grp = getgrgid(L(list)->stat->st_gid);
			max_list2(L(list), &max[0], &max[1]);
			max[2] = max[2] < (int)ft_strlen(passwd->pw_name) \
					? ft_strlen(passwd->pw_name) : max[2];
			max[3] = max[3] < (int)ft_strlen(grp->gr_name) ? \
					ft_strlen(grp->gr_name) : max[3];
			tot_size += L(list)->stat->st_blocks;
		}
		list = list->next;
	}
	return (tot_size);
}
