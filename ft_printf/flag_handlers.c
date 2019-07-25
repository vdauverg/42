/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:23:24 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/24 12:32:38 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_s(va_list args, t_printf *node)
{
	char	*str;

	str = va_arg(args, char*);
	if (!str)
		str = "(null)";
	if (node->length != -1)
		return(ft_strndup(str, node->length));
	return (ft_strdup(str));
}

char	*flag_c(va_list args, t_printf *node)
{
	char	*str;

	node++;
	str = ft_strdup(" ");
	*str = (char)va_arg(args, int);
	return (str);
}

char	*flag_p(va_list args, t_printf *node)
{
	char			*str;
	unsigned long	num;

	num = (unsigned long)(va_arg(args, void *));
	if (!num && !node->length)
		str = ft_strnew(0);
	else
		str = ft_itoabase(num, 16, 0);
	str = ft_strjoinfreelast("0x", str);
	return (str);
}

char	*flag_x(va_list args, t_printf *node)
{
	char				*str;
	unsigned long long	num;

	num = unsigned_vars(args, *node);
	str = ft_itoabase(num, 16, 0);
	str = ft_prec(str, node->length);
	if (node->alt && num)
	{
		if ((node->zero) && \
				(str = ft_pad(str, node->pad - 2, node->zero, node->align)))
			node->pad = 0;
		str = ft_strjoinfreelast("0x", str);
	}
	else if (!node->length && !num)
		return (ft_strdup(""));
	return (str);
}

char	*flag_xupper(va_list args, t_printf *node)
{
	char				*str;
	unsigned long long	num;

	num = unsigned_vars(args, *node);
	str = ft_itoabase(num, 16, 1);
	str = ft_prec(str, node->length);
	if (node->alt && num)
	{
		if ((node->zero) && \
				(str = ft_pad(str, node->pad - 2, node->zero, node->align)))
			node->pad = 0;
		str = ft_strjoinfreelast("0X", str);
	}
	else if (!node->length && !num)
		return (ft_strdup(""));
	return (str);
}

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

char	*flag_i(va_list args, t_printf *node)
{
	long long	num;
	char		*str;

	num = signed_vars(args, *node);
	(node->length != -1) ? node->zero = 0: 0;
	if (node->sign && num >= 0 && (str = ft_itoa(num)))
	{
		if ((node->zero) && (str = ft_pad(\
				str, node->pad - 1, node->zero, node->align)))
			node->pad = 0;
		return (ft_strjoinfreelast("+", ft_prec(str, node->length)));
	}
	else if (node->space && num >= 0)
		return (ft_strjoinfreelast(" ", ft_prec(ft_itoa(num), node->length)));
	else if (!node->length && !num)
		return (ft_strdup(""));
	else if (num < 0 && (str = ft_prec((num == -9223372036854775807 - 1) ? \
			ft_strdup("9223372036854775808") : ft_itoa(-num), node->length)))
	{
		if (node->zero)
			return (ft_strjoinfreelast("-", \
				ft_pad(str, node->pad - 1, node->zero, node->align)));
		else
			return (ft_strjoinfreelast("-", str));
	}
	return (ft_prec(ft_itoa(num), node->length));
}

long long	signed_vars(va_list args, t_printf node)
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

char	*flag_f(va_list args, t_printf *node)
{
	long double	num;

	if (node->l == 3)
		num = va_arg(args, long double);
	else
		num = (long double)va_arg(args, double);
	if (num == 1.0 / 0.0)
		return (ft_strdup("INF"));
	else if (num == -1.0 / 0.0)
		return (ft_strdup("-INF"));
	else if (num != num)
		return (ft_strdup("NAN"));
	else if (node->sign && num >= 0 && num != -0)
		return (ft_strjoinfreelast("+", ft_ftoa(num, \
				(node->length == -1) ? 6 : node->length, node->alt)));
	else if (node->space && num >= 0 && num != -0)
		return (ft_strjoinfreelast(" ", ft_ftoa(num, \
				(node->length == -1) ? 6 : node->length, node->alt)));
	else
		return (ft_ftoa(num, \
				(node->length == -1) ? 6 : node->length, node->alt));
}

char	*flag_o(va_list args, t_printf *node)
{
	char				*str;
	unsigned long long	num;

	num = unsigned_vars(args, *node);
	if (!node->length && !num)
		str = ft_strdup("");
	else
		str = ft_itoabase(num, 8, 0);
	if (node->alt)
		(num || (!num && !node->length)) ? str = ft_strjoinfreelast("0", str) : 0;
	str = ft_prec(str, node->length);
	return (str);
}

char	*flag_u(va_list args, t_printf *node)
{
	char				*str;
	unsigned long long	num;

	num = unsigned_vars(args, *node);
	if (!node->length && !num)
		str = ft_strdup("");
	else
		str = ft_itoabase(num, 10, 0);
	str = ft_prec(str, node->length);
	return (str);
}

char	*flag_b(va_list args, t_printf *node)
{
	char				*str;
	unsigned long long	num;

	num = unsigned_vars(args, *node);
	if (!node->length && !num)
		str = ft_strdup("");
	else
		str = ft_itoabase(num, 2, 0);
	str = ft_prec(str, node->length);
	return (str);
}