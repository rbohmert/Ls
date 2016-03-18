/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:51:54 by nrandria          #+#    #+#             */
/*   Updated: 2016/02/02 19:06:38 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		itoa_is_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int			tmp_n;
	int			len;
	int			neg;
	char		*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp_n = n;
	len = 2;
	neg = 0;
	itoa_is_neg(&n, &neg);
	while (tmp_n /= 10)
		len++;
	len += neg;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
