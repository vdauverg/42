/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 23:23:24 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/11 19:39:47 by vdauverg         ###   ########.fr       */
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
		return (ft_strndup(str, node->length));
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
	if (node->length != -1)
		str = ft_pad(str, node->length, 1, node->align);
	str = ft_strjoinfreelast("0x", str);
	return (str);
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
