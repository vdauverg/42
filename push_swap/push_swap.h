/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:25:07 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/18 00:09:19 by vincent          ###   ########.fr       */
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
void			swap_one(t_stack **stack, t_stack **last);
void			swap_all(t_stack **a, t_stack **b, t_stack **lasta, t_stack \
						**lastb);
void			push(t_stack **stack1, t_stack **stack2, t_stack **last1, \
						t_stack **last2);
void			rot_one(t_stack **stack, t_stack **last);
void			rot_all(t_stack **a, t_stack **b, t_stack **lasta, t_stack \
						**lastb);
void			rev_rot_one(t_stack **stack, t_stack **last);
void			rev_rot_all(t_stack **a, t_stack **b, t_stack **lasta, \
						t_stack **lastb);
t_stack			*cut_node(t_stack **stack, t_stack **last);
void			prepend_node(t_stack **stack, t_stack **last, t_stack *node);


#endif
