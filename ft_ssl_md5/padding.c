/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:40:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/29 11:45:46 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	count_bits(char *str)
{
	uint64_t	bits;

	bits = 0;
	while (*str)
	{
		bits += 8;
		str++;
	}
	return (bits);
}

int			pad_bits(char **str)
{
	uint64_t	bits;
	uint64_t	orig_len;
	int			i;
	int			diff;
	char		*pad;

	bits = count_bits(*str) + 8;
	diff = 448 - bits % 512;
	if (diff < 0)
		diff += 512;
	bits += diff + 64;
	pad = ft_strnew(bits / 8);
	pad = ft_strcpy(pad, *str);
	orig_len = ft_strlen(*str);
	i = orig_len;
	pad[i] = (char)128;
	while (++i < (bits / 8) - 8)
		pad[i] = 0;
	i = -1;
	while (++i < 8)
		pad[(bits / 8) - 1 - i] = orig_len >> (i * 8);
	free(*str);
	*str = pad;
	return (bits / 512);
}
