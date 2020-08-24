/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:45:46 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:49:08 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
