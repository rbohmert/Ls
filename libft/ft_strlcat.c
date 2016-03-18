/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:22:46 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/02 19:40:17 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		j;
	int		a;
	size_t	i;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
	{
		if (i == size)
			return (size + ft_strlen(src));
		i++;
	}
	a = i;
	while (src[j] != '\0' && i < (size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (src[j] != '\0')
		j++;
	dst[i] = '\0';
	return (a + j);
}
