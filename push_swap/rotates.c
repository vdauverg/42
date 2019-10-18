/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:41:34 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/18 00:12:27 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_one(t_stack **stack, t_stack **last)
{
	*last = (*last)->next;
	*stack = (*stack)->next;
}

void	rot_all(t_stack **a, t_stack **b, t_stack **lasta, t_stack **lastb)
{
	rot_one(a, lasta);
	rot_one(b, lastb);
}

void	rev_rot_one(t_stack **stack, t_stack **last)
{
	*last = (*last)->prev;
	*stack = (*stack)->prev;
}

void	rev_rot_all(t_stack **a, t_stack **b, t_stack **lasta, t_stack **lastb)
{
	rev_rot_one(a, lasta);
	rev_rot_one(b, lastb);
}
