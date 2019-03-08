/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 00:48:32 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/05 15:05:05 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	i = -1;
	dst2 = (char *)dst;
	src2 = (const char *)src;
	while (src2 < dst2 && len--)
		dst2[len] = src2[len];
	while (src2 > dst2 && ++i < len)
		dst2[i] = src2[i];
	return (dst);
}
