/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:28:39 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/20 19:56:21 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

size_t	count_bits(char *str)
{
	size_t	bits;

	bits = 0;
	while (*str)
	{
		bits += 8;
		str++;
	}
	return (bits);
}

int		pad_bits(char **str)
{
	size_t	bits;
	int		i;
	int		diff;
	char	c;
	char	*pad;

	pad = NULL;
	c = (char)128;
	bits = count_bits(*str) + 8;
	*str = ft_strjoinfreefirst(*str, &c);
	diff = 448 - bits % 512;
	if (diff < 0)
		diff += 512;
	if (diff)
	{
		pad = ft_strnew(diff / 8);
		*str = ft_strjoinfreeall(*str, pad);
	}
	bits += diff;
	pad = ft_strnew(8);
	i = -1;
	while (pad[++i])
		pad[i] = bits >> (7 - i);
	*str = ft_strjoinfreeall(*str, pad);
	return (bits);
}

char	*md5(char *str, t_metadata meta)
{
	size_t	bits;
	int		blocks;
	int		i;

	bits = pad_bits(&str);
	blocks = bits / 512;
	i = 0;
	while (i < blocks)
	{
		hash_block(str + (i * (512 / 8)));
		i++;
	}
	return ("");
}

char	*sha256(char *str, t_metadata meta)
{
	return ("");
}

char	*sha512(char *str, t_metadata meta)
{
	return ("");
}
