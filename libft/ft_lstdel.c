/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:43:31 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/02 19:48:54 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	while (*alst)
	{
		lst = *alst;
		*alst = (*alst)->next;
		del((lst)->content, (lst)->content_size);
		free(lst);
	}
}
