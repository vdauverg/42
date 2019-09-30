/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:02:13 by vdauverg          #+#    #+#             */
/*   Updated: 2019/09/22 14:01:13 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ftoa_precmod(int precision, long double num)
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

char	*ft_ftoa(long double num, int precision, int alt)
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
