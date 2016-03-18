/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:14:17 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/01 16:15:23 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	i = 0;
	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (dst);
}
