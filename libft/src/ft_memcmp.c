/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:44:34 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:50:04 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1b;
	unsigned char	*s2b;

	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*s1b == *s2b && --n)
	{
		s1b++;
		s2b++;
	}
	return (*s1b - *s2b);
}
