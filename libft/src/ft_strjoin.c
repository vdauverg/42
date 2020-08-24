/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:58:45 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:52:31 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		s1len;
	int		len;
	char	*s3;

	if (s1 && s2)
	{
		i = 0;
		s1len = ft_strlen(s1);
		len = (s1len + ft_strlen(s2)) * sizeof(char);
		if ((s3 = ft_strnew(len)))
		{
			s3 = (char *)ft_memcpy(s3, s1, (s1len * sizeof(char)));
			s3 += s1len;
			s3 = ft_strcpy(s3, s2);
			s3 -= s1len;
			return (s3);
		}
	}
	return (NULL);
}
