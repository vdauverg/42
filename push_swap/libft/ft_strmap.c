/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:33:00 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/04 12:15:22 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*s2;
	int		i;

	if (s && f)
	{
		i = ft_strlen(s);
		if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		s2[i] = '\0';
		i = 0;
		while (*s)
			s2[i++] = f(*s++);
		return (s2);
	}
	return (NULL);
}
