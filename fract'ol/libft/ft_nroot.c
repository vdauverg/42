/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nroot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:54:36 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 13:56:20 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nroot(unsigned long long num, int n)
{
	int					exponent;
	unsigned long long	res;

	exponent = 1;
	if (num == 1 || !num)
		return (1);
	while ((res = ft_exponent(n, exponent)) && res <= num)
		exponent++;
	return (exponent);
}
