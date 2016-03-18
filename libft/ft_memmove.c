/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:20:10 by nrandria          #+#    #+#             */
/*   Updated: 2016/02/02 18:32:51 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*tmp_dst;
	const char		*tmp2_src;

	tmp_dst = dst;
	tmp2_src = src;
	if (len <= 0)
		return (dst);
	if (tmp_dst < tmp2_src)
		while (len-- > 0)
			*tmp_dst++ = *tmp2_src++;
	else
	{
		tmp_dst += len;
		tmp2_src += len;
		while (len-- > 0)
			*--tmp_dst = *--tmp2_src;
	}
	return (dst);
}
