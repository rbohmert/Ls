/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:35:06 by nrandria          #+#    #+#             */
/*   Updated: 2015/11/26 13:55:42 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (s1[i] == s2[i] && s1[i])
			i++;
		if (s1[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
