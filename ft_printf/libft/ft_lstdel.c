/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:41:42 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/05 15:23:53 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*curr;
	t_list	*nxt;

	if (alst)
	{
		curr = *alst;
		while (curr)
		{
			nxt = curr->next;
			ft_lstdelone(&curr, del);
			curr = nxt;
		}
		*alst = NULL;
	}
}
