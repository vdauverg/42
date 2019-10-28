/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:21:38 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/25 22:06:37 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*read_file(char *file)
{
	int		fd;
	char	*line;
	char	*str;

	fd = open(file, O_RDONLY);
	str = NULL;
	// while (get_next_line(fd, &line) > 0)
	// {
	// 	line = ft_strjoinfreefirst(line, "\n");
	// 	if (str)
	// 		str = ft_strjoinfreefirst(str, line);
	// 	else
	// 		str = ft_strdup(line);
	// 	free(line);
	// }
	// str[ft_strlen(str) - 1] = 0;
	str = ft_strdup("pickle rick");
	return (str);
}

char	**read_files(int count, char **files)
{
	int		i;
    char    **strs;

	strs = (char **)malloc(sizeof(char *) * (count + 1));
	strs[count] = NULL;
	i = 0;
	while (i < count)
	{
		strs[i] = read_file(files[i]);
		i++;
	}
    return (strs);
}
