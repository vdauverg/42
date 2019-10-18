/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:16:48 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/10 19:17:49 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	unsigned_vars(va_list args, t_printf node)
{
	unsigned long long	num;

	if (node.l == 1)
		num = va_arg(args, unsigned long);
	else if (node.l == 2)
		num = va_arg(args, unsigned long long);
	else if (node.j == 1)
		num = va_arg(args, uintmax_t);
	else if (node.z == 1)
		num = va_arg(args, size_t);
	else if (node.h == 1)
		num = (unsigned short)va_arg(args, unsigned int);
	else if (node.h == 2)
		num = (unsigned char)va_arg(args, unsigned int);
	else
		num = va_arg(args, unsigned int);
	return (num);
}

long long			signed_vars(va_list args, t_printf node)
{
	long long	num;

	if (node.l == 1)
		num = va_arg(args, long);
	else if (node.l == 2)
		num = va_arg(args, long long);
	else if (node.j == 1)
		num = va_arg(args, intmax_t);
	else if (node.z == 1)
		num = va_arg(args, ssize_t);
	else if (node.h == 1)
		num = (short)va_arg(args, int);
	else if (node.h == 2)
		num = (signed char)va_arg(args, int);
	else
		num = va_arg(args, int);
	return (num);
}
