/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:15:34 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/02 20:15:12 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = ft_memalloc(content_size);
		ft_memcpy(list->content, content, content_size);
	}
	list->next = NULL;
	return (list);
}
