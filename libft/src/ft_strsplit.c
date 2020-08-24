/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 09:31:46 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:54:05 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_newsplitword(char **split, const char *s, char c)
{
	int	wlen;
	int	k;
	int	i;

	if (split && s)
	{
		wlen = ft_sublen(s, c);
		if ((*split = (char *)malloc(sizeof(char) * (wlen + 1))))
		{
			(*split)[wlen] = '\0';
			k = 0;
			i = 0;
			while (wlen-- > 0)
				(*split)[k++] = s[i++];
			return (i);
		}
	}
	return (0);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		splitlen;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	splitlen = ft_splitcount(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (splitlen + 1))))
		return (NULL);
	split[splitlen] = NULL;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			if (!(i += ft_newsplitword(&split[j], (s + i), c)))
				return (NULL);
			j++;
		}
	}
	return (split);
}
