/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:21:38 by vdauverg          #+#    #+#             */
/*   Updated: 2019/11/16 15:15:37 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*read_file(char *file)
{
	int		fd;
	char	*tmp;
	char	*str;

	fd = open(file, O_RDONLY);
	str = ft_strnew(0);
	tmp = ft_strnew(256);
	while (read(fd, tmp, 256) > 0)
		str = ft_strjoin(str, tmp);
	close(fd);
	return (str);
}
