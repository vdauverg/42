/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:03:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/14 21:01:28 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(int count, char **args)
{
	int		i;
	t_stack	*a;
	t_stack	*b;
	t_stack	*lasta;
	t_stack	*lastb;

	i = 0;
	a = init_stack(args, count, &lasta);
	b = NULL;
	lastb = NULL;
	swap_one(&a);
	push(&a, &b, &lastb);
	push(&a, &b, &lastb);
	push(&a, &b, &lastb);
	rot_all(&a, &b);
	rev_rot_all(&a, &b);
	swap_one(&a);
	push(&b, &a, &lasta);
	push(&b, &a, &lasta);
	push(&b, &a, &lasta);
	while (i < count)
	{
		ft_putnbr(a->val);
		ft_putendl("");
		a = a->next;
		i++;
	}
}

int		main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (!ft_isnum(argv[i]))
			{
				ft_putstr("Error\n");
				return (0);
			}
			i++;
		}
		checker(--argc, ++argv);
	}
	return (0);
}
