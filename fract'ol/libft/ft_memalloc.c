/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 19:15:16 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/05 15:19:17 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*arr;
	unsigned char	*arr2;

	if (size == 0 || !(arr = malloc(size)))
		return (NULL);
	arr2 = (unsigned char*)arr;
	while (size--)
		*arr2++ = 0;
	return (arr);
}
