/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:44:40 by nrandria          #+#    #+#             */
/*   Updated: 2015/11/30 16:38:49 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int res;

	i = 0;
	neg = 0;
	res = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (res *= -1);
	return (res);
}
