/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:17:43 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/11 22:39:35 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2, t_stack **last)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->val = (*stack1)->val;
	if (*stack2)
	{
		node->next = (*stack2);
		(*stack2)->prev = node;
		node->prev = *last;
		(*last)->next = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
		*stack2 = node;
		*last = *stack2;
	}
	if ((*stack1)->next != *stack1)
	{
		(*stack1)->prev->next = (*stack1)->next;
		(*stack1)->next->prev = (*stack1)->prev;
		node = (*stack1)->next;
		free(*stack1);
		*stack1 = node;
	}
	else
	{
		free(*stack1);
		*stack1 = NULL;
	}
}
