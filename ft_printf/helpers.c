/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:35:28 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/24 17:20:20 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_exponent(unsigned long long num, int exp)
{
	unsigned long long	res;

	res = 1;
	while (exp-- > 0)
		res *= num;
	return (res);
}

int					ft_nroot(unsigned long long num, int n)
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

char				*ft_itoabase(unsigned long long num, int base, int upper)
{
	int		i;
	int		rem;
	char	*str;
	char	*base_chars;

	base_chars = "0123456789abcdef";
	if (!num && (str = ft_strdup("0")))
		return (str);
	i = ft_nroot(num, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (num > 0)
	{
		rem = (num % base);
		if (upper && rem > 9)
			rem = base_chars[rem] - 32;
		else
			rem = base_chars[rem];
		str[--i] = (char)rem;
		num /= base;
	}
	return (str);
}

char				*ft_ftoa(long double num, int precision, int alt)
{
	int					i;
	unsigned long long	rnd;
	char				*str;

	rnd = (unsigned long long)num;
	str = ft_itoa(rnd);
	if (num < 0 && (num *= -1))
		rnd *= -1;
	num -= rnd;
	if (precision || (!precision && alt))
		str = ft_strjoinfreeall(str, ftoa_precmod(precision, num));
	i = ft_strlen(str);
	if ((num - (int)num) >= 0.5)
	{
		while (i && (str[--i] == '9' || str[i] == '.'))
			(str[i] != '.') ? str[i] = '0' : 0;
		str[i] += 1;
	}
	return (str);
}

char				*ftoa_precmod(int precision, long double num)
{
	char	*str;
	int		len;
	int		i;

	len = precision + 1;
	str = ft_strnew(len);
	str[0] = '.';
	i = 1;
	if (precision)
	{
		while (i <= len && (num - (int)num) > (1.0 / \
				ft_exponent(10, precision - i + 1)))
		{
			num = (num - (int)num) * 10;
			str[i++] = (int)num + '0';
		}
		if (i < len && ((num = (num - (int)num) * 10) || !num))
			str[i++] = (int)num + '0';
		while (i < len)
			str[i++] = '0';
	}
	return (str);
}

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
