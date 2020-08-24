/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:36:12 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:49:26 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list **alst, void (del)(void *, size_t))
{
	if (alst && del)
	{
		(del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
