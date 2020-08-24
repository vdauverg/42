/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:21:14 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:52:21 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = ft_strnew(ft_strlen(s1) * sizeof(char))))
		return (NULL);
	dup = ft_strcpy(dup, s1);
	return (dup);
}
