/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:41:00 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/04 12:17:03 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s2;

	if (s && f)
	{
		i = ft_strlen(s);
		if (!(s2 = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		s2[i] = '\0';
		i = 0;
		while (*s)
		{
			s2[i] = f(i, *s++);
			i++;
		}
		return (s2);
	}
	return (NULL);
}
