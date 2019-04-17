/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:10:52 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/04 12:21:07 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_strtrim(const char *s)
{
	char	*s2;
	long	i;
	long	j;
	long	size;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		size = j - i + 1;
		if (size < 0)
			size = 0;
		if (!(s2 = (char *)ft_memalloc((size + 1) * sizeof(char))))
			return (NULL);
		j = 0;
		while (j < size)
			s2[j++] = s[i++];
		return (s2);
	}
	return (NULL);
}
