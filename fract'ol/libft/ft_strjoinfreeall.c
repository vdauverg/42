/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreeall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:14:53 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/11 19:16:34 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfreeall(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 && s2 && (s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		i = 0;
		while ((s1[i] ? s3[i] = s1[i] : 0))
			i++;
		ft_strdel(&s1);
		j = 0;
		while ((s2[j] ? s3[i + j] = s2[j] : 0))
			j++;
		ft_strdel(&s2);
		s3[i + j] = 0;
		return (s3);
	}
	else
		return (NULL);
}
