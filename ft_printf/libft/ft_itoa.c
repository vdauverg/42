/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:45:46 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/21 13:40:02 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	char	*s;
	int		i;
	int		neg;

	neg = 0;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	i = ft_numlen(n) + 1;
	if (!(s = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	s[--i] = '\0';
	if (n < 0)
	{
		neg = 1;
		*s++ = '-';
		i--;
		n *= -1;
	}
	while (i-- > 0)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	return (s - neg);
}
