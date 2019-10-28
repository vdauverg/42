/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:28:39 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/28 00:59:33 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t		rot_bits(uint32_t a, uint32_t n)
{
	return (a << n | a >> (32 - n));
}

uint32_t		*rot_words(uint32_t *words)
{
	uint32_t	tmp;

	tmp = words[3];
	words[3] = words[2];
	words[2] = words[1];
	words[1] = words[0];
	words[0] = tmp;
	return (words);
}

uint32_t		*do_aux_funcs(uint32_t *w, uint32_t *m)
{
	int				i;

	i = -1;
	while (++i < 16)
	{
		w[0] = rot_bits(w[0] + F(w[1], w[2], w[3]) + m[i] + g_k[i], g_s[i]) + w[1];
		w = rot_words(w);
	}
	while (++i < 32)
	{
		w[0] = rot_bits(w[0] + G(w[1], w[2], w[3]) + m[(5 * i + 1) % 16] + g_k[i], g_s[i]) + w[1];
		w = rot_words(w);
	}
	while (++i < 48)
	{
		w[0] = rot_bits(w[0] + H(w[1], w[2], w[3]) + m[(3 * i + 5) % 16] + g_k[i], g_s[i]) + w[1];
		w = rot_words(w);
	}
	while (++i < 64)
	{
		w[0] = rot_bits(w[0] + I(w[1], w[2], w[3]) + m[(7 * i) % 16] + g_k[i], g_s[i]) + w[1];
		w = rot_words(w);
	}
	return (w);
}

uint32_t		*abcd_init(void)
{
	uint32_t	*words;

	words = (uint32_t *)malloc(sizeof(uint32_t) * 4);
	words[0] = A;
	words[1] = B;
	words[2] = C;
	words[3] = D;
	return (words);
}

unsigned char	*md5(char *str, t_metadata meta)
{
	int				i;
	int				j;
	uint32_t		*words;
	uint32_t		*hash;
	uint32_t		*split;
	unsigned char	*res;

	words = abcd_init();
	hash = abcd_init();
	split = (uint32_t *)malloc(sizeof(uint32_t) * 16);
	i = pad_bits(&str);
	j = 0;
	while (j < 16)
	{
		split[j] = str[(j * 4)] << 24;
		split[j] += str[(j * 4) + 1] << 16;
		split[j] += str[(j * 4) + 2] << 8;
		split[j] += str[(j * 4) + 3];
		j++;
	}
	while (i > 0)
	{
		hash = do_aux_funcs(hash, split);
		hash[0] += words[0];
		hash[1] += words[1];
		hash[2] += words[2];
		hash[3] += words[3];
		i--;
	}
	res = (unsigned char *)malloc(sizeof(unsigned char) * 33);
	res[32] = 0;
	i = 0;
	while (i < 32)
	{
		res[i] = hash[i / 4] >> (24 - 8 * (i % 4));
		i++;
	}
	return (res);
}

unsigned char	*sha256(char *str, t_metadata meta)
{
	unsigned char	*hash;

	return (hash);
}

unsigned char	*sha512(char *str, t_metadata meta)
{
	unsigned char	*hash;

	return (hash);
}
