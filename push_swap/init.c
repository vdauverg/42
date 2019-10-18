/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:02:37 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/11 20:41:42 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **args, int count, t_stack **last)
{
	int		i;
	t_stack	*head;
	t_stack *node;

	i = 0;
	while (i < count)
	{
		if (!i)
		{
			head = (t_stack *)malloc(sizeof(t_stack));
			node = head;
		}
		node->val = ft_atoi(args[i]);
		node->next = (t_stack *)malloc(sizeof(t_stack));
		node->next->prev = node;
		node = node->next;
		i++;
	}
	node = node->prev;
	free(node->next);
	node->next = head;
	head->prev = node;
	*last = node;
	return (head);
}
