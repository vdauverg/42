/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:54:36 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 13:57:08 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_exponent(unsigned long long num, int exp)
{
	unsigned long long	res;

	res = 1;
	while (exp-- > 0)
		res *= num;
	return (res);
}
