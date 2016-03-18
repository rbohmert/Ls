/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:11:33 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/01 14:12:19 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) - 1;
	if (!c)
		return ((char *)s + i + 1);
	while (s[i] != 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char *)s + i);
	else
		return (0);
}
