/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:43:55 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/08 17:05:45 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstat(t_list **list, unsigned int n)
{
	t_list			*buf;
	unsigned int	i;

	i = 0;
	buf = *list;
	if (!list)
		return (NULL);
	while (i < n)
		buf = buf->next;
	return (buf);
}
