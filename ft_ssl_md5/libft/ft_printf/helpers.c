/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:35:28 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/10 19:02:51 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strscat(char *dst, char *src, int start)
{
	while (dst[start])
	{
		dst[start] = *src++;
		start++;
	}
	return (dst);
}

char				*ft_strldup(const char *src, int len)
{
	int		i;
	char	*str;

	str = ft_strnew(len);
	i = 0;
	while (src[i] && i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

char				*ft_pad(char *str, int padlen, int zero, int align)
{
	char	*tmp;

	if (padlen < 0 && (align = 1))
		padlen *= -1;
	if (zero == 1 && align)
		zero = 0;
	if (*str)
		padlen -= ft_strlen(str);
	if (padlen > 0)
	{
		tmp = ft_strnew(padlen);
		while (--padlen > -1)
			(zero == 1) ? tmp[padlen] = '0' : \
				(tmp[padlen] = ' ');
		if (align)
			str = ft_strjoinfreeall(str, tmp);
		else
			str = ft_strjoinfreeall(tmp, str);
	}
	return (str);
}

char				*ft_prec(char *str, int prec)
{
	char	*tmp;
	int		len;

	if ((len = prec - ft_strlen(str)) > 0)
	{
		tmp = ft_strnew(len);
		tmp = ft_memset((void *)tmp, '0', len);
		str = ft_strjoinfreeall(tmp, str);
	}
	return (str);
}
