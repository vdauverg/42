/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 13:06:58 by vincent           #+#    #+#             */
/*   Updated: 2019/08/10 11:19:06 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 			ft_isbase(char c, int base)
{
	int ret;
	c = ft_tolower(c);
	if (ft_isalpha(c))
		ret = c - 'a' + 10;
	else
		ret = c - '0';
	if (ret < base)
		return (ret);
	return (-1);
}

unsigned int	ft_atoibase(const char *str, int base)
{
	unsigned int	num;
	int				sign;
	int 			digit;

	num = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && (digit = ft_isbase((char) *str, base)) != -1)
	{
		num *= base;
		num += digit;
		str++;
	}
	return ((digit != -1) ? num * sign : 0);
}
