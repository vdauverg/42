/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:36:29 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:50:00 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s2;

	s2 = (const unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return ((void *)s);
		s2++;
		s++;
	}
	return (NULL);
}
