/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:36:50 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:54:18 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
