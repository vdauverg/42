/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:13:18 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:50:09 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst2;
	const unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	while (n--)
		*dst2++ = *src2++;
	return (dst);
}
