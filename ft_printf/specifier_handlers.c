/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:24:23 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/24 11:26:32 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*spec_prec(const char *format, va_list args, t_printf *node)
{
	int		i;
	char	*str;

	i = 0;
	node->length = 6;
	if (format[i] == '*' && (node->step += 2) && ++i)
		node->length = va_arg(args, int);
	else
	{
		while (format[i] && ft_isdigit(format[i]))
			i++;
		node->step += i + 1;
		if (!ft_isalpha(format[i]) && format[i] != '%')
		{
			node->length = 0;
			return (check_format(format + i, args, node));
		}
		str = ft_strldup(format, i);
		node->length = ft_atoi(str);
		free(str);
	}
	return (check_format(format + i, args, node));
}

char	*spec_alt(const char *format, va_list args, t_printf *node)
{
	node->alt++;
	node->step++;
	return (check_format(format, args, node));
}

char	*spec_zpad(const char *format, va_list args, t_printf *node)
{
	node->zero++;
	node->step++;
	return (check_format(format, args, node));
}

char	*spec_left(const char *format, va_list args, t_printf *node)
{
	node->align++;
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

char	*spec_pad(const char *format, va_list args, t_printf *node)
{
	int		i;
	char	*str;

	i = 0;
	if (format[i] == '*' && (node->step += 2) && ++i)
		node->pad = va_arg(args, int);
	else
	{
		while (format[i] && ft_isdigit(format[i]))
			i++;
		node->step += i;
		str = ft_strldup(format, i);
		node->pad = ft_atoi(str);
		free(str);
	}
	str = check_format(format + i, args, node);
	return (ft_pad(str, node->pad, node->zero, node->align));
}

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

char	*spec_star(const char *format, va_list args, t_printf *node)
{
	char	*str;

	node->step++;
	if (!node->pad)
		node->pad = va_arg(args, int);
	else
		va_arg(args, int);
	str = check_format(format, args, node);
	return (ft_pad(str, node->pad, node->zero, node->align));
}
