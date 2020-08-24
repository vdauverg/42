/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:21:10 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:53:38 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
