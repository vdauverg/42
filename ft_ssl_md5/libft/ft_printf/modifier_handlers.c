/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 16:13:20 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/11 16:13:49 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*spec_alt(const char *format, va_list args, t_printf *node)
{
	node->alt++;
	node->step++;
	return (check_format(format, args, node));
}

char	*spec_sign(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->sign++;
	return (check_format(format, args, node));
}

char	*spec_space(const char *format, va_list args, t_printf *node)
{
	node->step++;
	node->space = 1;
	return (check_format(format, args, node));
}
