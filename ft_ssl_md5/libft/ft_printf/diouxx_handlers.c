/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:07:08 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/11 18:14:42 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_i(va_list args, t_printf *node)
{
	long long	num;
	char		*str;

	num = signed_vars(args, *node);
	(node->length != -1) ? node->zero = 0 : 0;
	if (node->sign && num >= 0 && (str = ft_itoa(num)) && ((((node->zero) && \
			(str = ft_pad(str, node->pad - 1, node->zero, \
			node->align))) ? node->pad = 0 : 0) || 1))
		return (ft_strjoinfreelast("+", ft_prec(str, node->length)));
	else if (node->space && num >= 0)
		return (ft_strjoinfreelast(" ", ft_pad(ft_prec(ft_itoa(num), \
			node->length), node->pad - 1, node->zero, node->align)));
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
		(num || (!num && !node->length)) ? \
				str = ft_strjoinfreelast("0", str) : 0;
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
