/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:45:21 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/08 17:06:13 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_create_elem(void *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	else
	{
		elem->content = content;
		elem->content_size = content_size;
		elem->next = NULL;
	}
	return (elem);
}
