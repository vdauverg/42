/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:36:12 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/03 14:36:45 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (del)(void *, size_t))
{
	if (alst && del)
	{
		(del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
