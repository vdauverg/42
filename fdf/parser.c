/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:54 by vincent           #+#    #+#             */
/*   Updated: 2019/09/22 20:04:47 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*lst_fill(t_line *node, char *line)
{
	int		i;
	char	**data;
	char	**colour;

	data = ft_strsplit(line, ' ');
	node->length = 0;
	while (data[node->length])
		node->length++;
	node->xz = (int *)malloc(sizeof(int) * node->length);
	node->colour = (unsigned int *)malloc(sizeof(unsigned int) * node->length);
	i = -1;
	while (data[++i])
	{
		colour = ft_strsplit(data[i], ',');
		(colour[1]) ? node->colour[i] = ft_atoibase(colour[1] + 2, 16) : \
				(node->colour[i] = 0xFFFFFF);
		node->xz[i] = ft_atoi(*colour);
		free(data[i]);
		free(colour[0]);
		free(colour[1]);
		free(colour);
	}
	free(data);
	return (node);
}

t_line	*parse_map(char *file)
{
	int		fd;
	int		y;
	char	*line;
	t_line	*mat;
	t_line	*node;

	if ((fd = open(file, O_RDONLY)) < 3)
		return (NULL);
	mat = (t_line *)malloc(sizeof(t_line));
	node = mat;
	y = -1;
	while ((++y || 1) && get_next_line(fd, &line) > 0)
	{
		(y) ? node->next = (t_line *)malloc(sizeof(t_line)) : 0;
		(y) ? node = node->next : 0;
		node = lst_fill(node, line);
		(!y) ? mat->max_w = mat->length : 0;
		(node->length > mat->max_w) ? mat->max_w = node->length : 0;
		free(line);
	}
	free(line);
	close(fd);
	node->next = NULL;
	(mat) ? mat->max_h = y : 0;
	return (mat);
}
