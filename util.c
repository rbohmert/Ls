/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 23:44:11 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 01:07:09 by rbohmert         ###   ########.fr       */
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

int		nb_len(int nb)
{
	int i;

	i = 0;
	while ((nb = nb / 10))
		i++;
	return (i);
}

void	put_size(t_file *file, t_align *al)
{
	int i;
	int len;

	i = 1;
	if (!S_ISBLK(file->stat->st_mode) && !S_ISCHR(file->stat->st_mode))
	{
		len = nb_len(file->stat->st_size);
		while (i++ <= al->size - len + 1)
			ft_putchar(' ');
		ft_putnbr(file->stat->st_size);
		return ;
	}
	i = 0;
	len = nb_len(MAJOR(file->stat->st_rdev));
	while (i++ <= al->maj - len + 1)
		ft_putchar(' ');
	ft_putnbr(MAJOR(file->stat->st_rdev));
	i = 0;
	ft_putchar(',');
	len = nb_len(MINOR(file->stat->st_rdev));
	while (i++ <= al->min - len)
		ft_putchar(' ');
	ft_putnbr(MINOR(file->stat->st_rdev));
}
