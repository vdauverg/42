/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:56:16 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/01 17:43:27 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	int		i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = 0;
	if (dstsize <= dstl)
		return (dstsize + srcl);
	while (dst[i] && i < (int)(dstsize - 1))
		i++;
	while (i < (int)(dstsize - 1) && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (dstl + srcl);
}
