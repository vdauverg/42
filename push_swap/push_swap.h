/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:25:07 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/11 22:42:59 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_stack
{
	int				val;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack			*init_stack(char **args, int count, t_stack **last);
void			swap_one(t_stack **stack);
void			swap_all(t_stack **a, t_stack **b);
void			push(t_stack **stack1, t_stack **stack2, t_stack **last);
t_stack			*rot_one(t_stack *stack);
void			rot_all(t_stack **a, t_stack **b);
t_stack			*rev_rot_one(t_stack *stack);
void			rev_rot_all(t_stack **a, t_stack **b);

#endif
