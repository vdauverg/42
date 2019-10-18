/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:52:07 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/11 22:43:21 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_one(t_stack **stack)
{
	t_stack	*head;
	t_stack	*node;

	head = *stack;
	node = head->next;
	node->prev = head->prev;
	head->prev = node;
	head->next = node->next;
	node->next = head;
	*stack = node;
}

void	swap_all(t_stack **a, t_stack **b)
{
	swap_one(a);
	swap_one(b);
}
