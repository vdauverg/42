/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 23:37:55 by vincent           #+#    #+#             */
/*   Updated: 2019/10/18 00:22:36 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*cut_node(t_stack **stack, t_stack **last)
{
	t_stack	*node;

	node = *stack;
	if (node == node->next)
	{
		*stack = NULL;
		*last = NULL;
	}
	else
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = *last;
		(*last)->next = *stack;
	}
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	prepend_node(t_stack **stack, t_stack **last, t_stack *node)
{
	if (*stack)
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev = node;
		(*last)->next = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
		*last = node;
	}
	*stack = node;
}
