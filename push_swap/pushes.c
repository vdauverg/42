/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:17:43 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/18 00:18:12 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack1, t_stack **stack2, t_stack **last1, t_stack **last2)
{
	t_stack	*node;

	node = cut_node(stack1, last1);
	prepend_node(stack2, last2, node);
}
