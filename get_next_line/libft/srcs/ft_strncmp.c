/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 21:13:43 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/04 07:45:18 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (!n)
		return ((unsigned char)*--s1 - (unsigned char)*--s2);
	else
		return ((unsigned char)*s1 - (unsigned char)*s2);
}
