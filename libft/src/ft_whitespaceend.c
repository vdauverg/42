/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespaceend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:45:15 by vdauverg          #+#    #+#             */
/*   Updated: 2020/08/24 15:54:33 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_whitespaceend(char *str)
{
	if (!str || !*str)
		return (NULL);

	while (*str && ft_iswhitespace(*str))
		str++;

	return (str);
}
