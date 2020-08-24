/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 21:59:59 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:49:35 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new;
	t_list	*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		start = new;
		lst = lst->next;
		while (lst)
		{
			tmp = f(lst);
			if (!(new->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
