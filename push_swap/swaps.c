/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:52:07 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/17 23:30:15 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_stack **stack, t_stack **last)
{
	t_stack	*head;
	t_stack	*node;

	head = *stack;
	node = head->next;
	node->prev = head->prev;
	head->prev = node;
	head->next = node->next;
	node->next = head;
	(*last)->next = node;
	*stack = node;
}

void	swap_all(t_stack **a, t_stack **b, t_stack **lasta, t_stack **lastb)
{
	swap_one(a, lasta);
	swap_one(b, lastb);
}
