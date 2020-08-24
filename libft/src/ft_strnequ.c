/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:11:10 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:53:33 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		n++;
		while (s1[i] && n-- - 1)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if (!s2[i] || !n)
			return (1);
	}
	return (0);
}
