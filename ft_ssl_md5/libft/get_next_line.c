/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:09:37 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/20 13:34:56 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char	*fdlist[4096];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			isread;
	int			check;

	if (!line || fd < 0 || fd > 4096 || !(*line = ft_strnew(0)))
		return (-1);
	check = 0;
	ft_strclr(buff);
	(fdlist[fd] && *fdlist[fd] && (check = 1) && \
		(*line = ft_strjoinfreeall(fdlist[fd], *line)) && \
		(fdlist[fd] = NULL));
	if (!ft_strchr(*line, '\n'))
		while (!ft_strchr(buff, '\n') \
				&& (isread = read(fd, buff, BUFF_SIZE)) > 0 \
				&& !(buff[isread] = '\0') \
				&& (*line = ft_strjoinfreefirst(*line, buff)))
			check = 1;
	tmp = ft_strchr(*line, '\n');
	(tmp && *tmp && !(*tmp = '\0') && tmp++) ? \
		fdlist[fd] = ft_strdup(tmp) : 0;
	return ((**line || check == 1) ? 1 : isread);
}
