/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:38:52 by nrandria          #+#    #+#             */
/*   Updated: 2015/11/30 20:18:24 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	int		i;
	int		j;

	if ((ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[j] == '\0')
	{
		j--;
		while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		{
			j--;
		}
	}
	if (j < 0)
		return ("");
	ptr = ft_strsub(s, i, j - i + 1);
	return (ptr);
}
