/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:38:17 by nrandria          #+#    #+#             */
/*   Updated: 2015/11/27 13:27:46 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = 0;
	j = 0;
	if (ptr == NULL || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	if (s1[i] == '\0')
	{
		while (s2[j])
		{
			ptr[i] = s2[j];
			j++;
			i++;
		}
	}
	ptr[i] = '\0';
	return (ptr);
}
