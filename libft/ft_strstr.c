/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:54:04 by rbohmert          #+#    #+#             */
/*   Updated: 2015/12/01 19:22:05 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(s2) == 0)
		return (char *)(s1);
	while (s1[i])
	{
		j = i;
		k = 0;
		while (s2[k] == s1[j])
		{
			j++;
			k++;
			if (s2[k] == '\0')
				return (char *)(s1 + i);
		}
		i++;
	}
	return (NULL);
}
