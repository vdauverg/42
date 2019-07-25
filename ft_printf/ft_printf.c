/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 20:30:18 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/24 16:44:46 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*set_pfnode(t_printf *node)
{
	node = (t_printf *)malloc(sizeof(t_printf));
	node->l = 0;
	node->h = 0;
	node->j = 0;
	node->z = 0;
	node->length = -1;
	node->alt = 0;
	node->step = 0;
	node->align = 0;
	node->zero = 0;
	node->sign = 0;
	node->space = 0;
	node->pad = 0;
	return (node);
}

char		*check_format(const char *format, va_list args, t_printf *node)
{
	int			i;
	char		c;
	char		*flags;
	char		*(*flag_handler[])F_HANDLE;
	char		*(*spec_handler[])S_HANDLE;

	flags = "%diouxXfFcsbp.#0-+ hlLjz";
	c = *format;
	if ((ft_isdigit(c) && c != '0') || c == '*')
		return (spec_pad(format, args, node));
	i = 0;
	while (flags[i] && flags[i] != c)
		i++;
	if (flags[i] && i > 0 && i < 13)
		return (flag_handler[i - 1](args, node));
	else if (flags[i] && i > 12)
		return (spec_handler[i - 13](format + 1, args, node));
	else if (!i)
		return (ft_strdup("%"));
	else
	{
		node->step -= 1;
		return (ft_strdup(""));
	}
}

char		*parse_format(const char *format, va_list args)
{
	int			i;
	int			start;
	char		*str;
	char		*tmp;
	t_printf	*node;

	i = 0;
	while (format[i])
	{
		node = set_pfnode(node);
		if (format[i] == '%')
		{
			if (!(tmp = check_format(format + i + 1, args, node)))
				return (NULL);
			i += node->step + 2;
		}
		else
		{
			start = i;
			while (format[i] && format[i] != '%')
				i++;
			tmp = ft_strldup(format + start, i - start);
		}
		(str) ? str = ft_strjoinfreefirst(str, tmp) : \
			(str = ft_strdup(tmp));
		free(tmp);
		free(node);
	}
	return (str);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		args;
	int			len;
	char		*str;

	va_start(args, format);
	if (!(str = parse_format(format, args)))
	{
		va_end(args);
		return (0);
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	va_end(args);
	return (len);
}
