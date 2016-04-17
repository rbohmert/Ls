/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:23:13 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/15 23:07:26 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*current;
	t_list	*reverse;

	reverse = NULL;
	current = *begin_list;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
		tmp->next = reverse;
		reverse = tmp;
	}
	tmp = current;
	tmp->next = reverse;
	reverse = tmp;
	*begin_list = reverse;
}

int		cmp(t_list *lg, t_list *ld, int flag)
{
	if (flag == 1)
		return ((ft_strcmp(lg->content, ld->content) <= 0) ? 1 : 0);
	if (flag == 2)
	{
		return ((ft_strcmp(((t_file *)lg->content)->name,\
				((t_file *)ld->content)->name) <= 0) ? 1 : 0);
	}
	if (flag == 3)
	{
		if (L(lg)->stat->st_mtime == L(ld)->stat->st_mtime)
		{
			if (L(lg)->stat->st_mtimespec.tv_nsec \
					== L(ld)->stat->st_mtimespec.tv_nsec)
				return ((ft_strcmp(L(lg)->name, L(ld)->name) <= 0) ? 1 : 0);
			return ((L(lg)->stat->st_mtimespec.tv_nsec \
						> L(ld)->stat->st_mtimespec.tv_nsec) ? 1 : 0);
		}
		return ((L(lg)->stat->st_mtime >= L(ld)->stat->st_mtime) ? 1 : 0);
	}
	return (0);
}

t_list	*separer(t_list *list)
{
	t_list *aux;

	if (list == NULL)
		return (NULL);
	else if (list->next == NULL)
		return (NULL);
	else
	{
		aux = list->next;
		list->next = aux->next;
		aux->next = separer(aux->next);
		return (aux);
	}
}

t_list	*fusion(t_list *lg, t_list *ld, int flag)
{
	if (lg == NULL)
		return (ld);
	else if (ld == NULL)
		return (lg);
	else if (cmp(lg, ld, flag))
	{
		lg->next = fusion(lg->next, ld, flag);
		return (lg);
	}
	else
	{
		ld->next = fusion(lg, ld->next, flag);
		return (ld);
	}
}

void	trier(t_list **list, int flag)
{
	t_list *aux;

	if (*list != NULL)
	{
		if ((*list)->next != NULL)
		{
			aux = separer(*list);
			trier(list, flag);
			trier(&aux, flag);
			*list = fusion(*list, aux, flag);
		}
	}
}
