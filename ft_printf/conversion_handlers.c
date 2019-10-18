/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:24:23 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/11 16:13:52 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*spec_h(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->h++;
	return (check_format(format, args, node));
}

char	*spec_l(const char *format, va_list args, t_printf *node)
{
	node->step++;
	if (node->l < 3)
		node->l++;
	return (check_format(format, args, node));
}

char	*spec_capl(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->l = 3;
	return (check_format(format, args, node));
}

char	*spec_j(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->j = 1;
	return (check_format(format, args, node));
}

char	*spec_z(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->z = 1;
	return (check_format(format, args, node));
}
