/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 10:33:43 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/02 22:26:09 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_splitcount(const char *s, const char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
				count++;
			i++;
		}
		return (count);
	}
	return (0);
}
