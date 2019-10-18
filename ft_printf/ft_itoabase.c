/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:55:38 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/10 18:56:07 by vdauverg         ###   ########.fr       */
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
	if (!num)
		return (ft_strdup("0"));
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
