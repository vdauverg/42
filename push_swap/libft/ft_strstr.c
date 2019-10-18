/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:32:23 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/05 21:44:41 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	if (!*needle || !needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && *needle)
	{
		if (haystack[i] == *needle)
		{
			if (!ft_strncmp((haystack + i), needle, ft_strlen(needle)))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
