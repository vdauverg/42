/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:21:10 by vdauverg          #+#    #+#             */
/*   Updated: 2019/02/24 07:56:14 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) + size)))
	{
		size++;
		while (size--)
			str[i++] = '\0';
		return (str);
	}
	return (NULL);
}
