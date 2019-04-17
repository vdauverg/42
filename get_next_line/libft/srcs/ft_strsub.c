/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:36:50 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/04 07:48:54 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	int		i;

	i = 0;
	if ((s2 = ft_strnew(len)) && s)
	{
		s2[len] = '\0';
		while (s[start] && len--)
			s2[i++] = s[start++];
		return (s2);
	}
	return (NULL);
}
