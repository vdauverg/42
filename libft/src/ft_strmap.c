/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:33:00 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:53:07 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
