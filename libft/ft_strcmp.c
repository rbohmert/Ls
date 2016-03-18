/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:03:15 by nrandria          #+#    #+#             */
/*   Updated: 2015/11/30 19:20:51 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, const char *s2)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (tmp1[i] == tmp2[i] && tmp1[i] && tmp2[i])
		i++;
	return (tmp1[i] - tmp2[i]);
}
