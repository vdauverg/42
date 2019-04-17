/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:09:37 by vdauverg          #+#    #+#             */
/*   Updated: 2019/04/17 09:40:00 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinfreefirst(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 && s2 && (s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		i = 0;
		while ((s1[i] ? s3[i] = s1[i] : 0))
			i++;
		ft_strdel(&s1);
		j = 0;
		while ((s2[j] ? s3[i + j] = s2[j] : 0))
			j++;
		s3[i + j] = 0;
		return (s3);
	}
	else
		return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static char	*fdlist[4096];
	char		*buff;
	int			isread;
	int			check;

	if (!line || fd < 0 || !(*line = ft_strnew(0)))
		return (-1);
	check = 0;
	(fdlist[fd] && *fdlist[fd] && (check = 1) &&
		(*line = ft_strjoin(fdlist[fd], *line))) ? ft_strdel(&(fdlist[fd])) : 0;
	while (!(buff = ft_strchr(*line, '\n')) &&
			(buff = ft_strnew(BUFF_SIZE))
			&& (isread = read(fd, buff, BUFF_SIZE)) > 0
			&& (check = 1)
			&& (*line = ft_strjoinfreefirst(*line, buff)))
		ft_strdel(&buff);
	(buff && !*buff) ? ft_strdel(&buff) : 0;
	(buff && *buff && !(*buff = '\0') && buff++) ?
		fdlist[fd] = ft_strdup(buff) : 0;
	return ((**line || check == 1) ? isread = 1 : isread);
}
