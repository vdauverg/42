/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:09:47 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:49:55 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	size_t				i;

	dst2 = dst;
	src2 = src;
	i = -1;
	while (++i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return ((void *)(dst + ++i));
	}
	return (NULL);
}
