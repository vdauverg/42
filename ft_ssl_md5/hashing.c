/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:28:39 by vdauverg          #+#    #+#             */
/*   Updated: 2019/11/12 14:53:18 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rot_bits(uint32_t a, uint32_t n)
{
	return (a << n | a >> (32 - n));
}

uint32_t	*rot_words(uint32_t *words, uint32_t res, int i)
{
	words[0] = words[3];
	words[3] = words[2];
	words[2] = words[1];
	words[1] = words[1] + rot_bits(res, g_s[i]);
	return (words);
}

uint32_t	hashing(uint32_t *abcd, uint32_t *str, int i)
{
	uint32_t	res;

	if (i < 16)
		res = F(abcd[1], abcd[2], abcd[3]) + str[i];
	else if (i < 32)
		res = G(abcd[1], abcd[2], abcd[3]) + str[(5 * i + 1) % 16];
	else if (i < 48)
		res = H(abcd[1], abcd[2], abcd[3]) + str[(3 * i + 5) % 16];
	else
		res = I(abcd[1], abcd[2], abcd[3]) + str[(7 * i) % 16];
	return (res + abcd[0] + g_k[i]);
}

uint32_t	*abcd_init(void)
{
	uint32_t	*words;

	words = (uint32_t *)malloc(sizeof(uint32_t) * 4);
	words[0] = A;
	words[1] = B;
	words[2] = C;
	words[3] = D;
	return (words);
}

uint32_t		*to_32bitstr(char *str, int blocks)
{
	uint32_t	*words;
	int			i;
	int			l;

	l = blocks * 512 / 8;
	words = (uint32_t *)malloc(sizeof(uint32_t) * (l / 4));
	i = 0;
	while (i < l)
	{
		words[i / 4] = str[i] << (24 - (i % 4 * 8));
		i++;
	}
	return (words);
}

unsigned char	*md5(char *str, t_metadata meta)
{
	int				i;
	int				blocks;
	unsigned char	*hash;
	uint32_t		res;
	uint32_t		*abcd0;
	uint32_t		*abcd;
	uint32_t		*words;

	abcd0 = abcd_init();
	blocks = pad_bits(&str);
	words = to_32bitstr(str, blocks);
	while (--blocks > -1)
	{
		abcd = abcd_init();
		i = -1;
		while (++i < 64)
		{
			res = hashing(abcd, words, i);
			abcd = rot_words(abcd, res, i);
		}
		abcd0[0] += abcd[0];
		abcd0[1] += abcd[1];
		abcd0[2] += abcd[2];
		abcd0[3] += abcd[3];
		free(abcd);
	}
	hash = (unsigned char *)malloc(sizeof(unsigned char) * 17);
	hash[16] = 0;
	i = -1;
	while (++i < 16)
		hash[i] = abcd0[i / 4] >> (8 * (i % 4));
	free(abcd0);
	return (hash);
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
