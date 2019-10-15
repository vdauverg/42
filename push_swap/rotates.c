/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:41:34 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/11 19:47:34 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rot_one(t_stack *stack)
{
	return (stack->next);
}

void	rot_all(t_stack **a, t_stack **b)
{
	*a = rot_one(*a);
	*b = rot_one(*b);
}

t_stack	*rev_rot_one(t_stack *stack)
{
	return (stack->prev);
}

void	rev_rot_all(t_stack **a, t_stack **b)
{
	*a = rev_rot_one(*a);
	*b = rev_rot_one(*b);
}
