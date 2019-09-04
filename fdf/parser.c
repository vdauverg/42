/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:54 by vincent           #+#    #+#             */
/*   Updated: 2019/09/03 15:08:45 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	*lst_fill(t_line *node, char *line)
{
	int		i;
	char	**data;
	char	**colour;

	data = ft_strsplit(line, ' ');
	i = 0;
	while (data[i])
		i++;
	node->xz = (int *)malloc(sizeof(int) * i);
	node->colour = (unsigned int *)malloc(sizeof(unsigned int) * i);
	node->length = i;
	i = 0;
	while (data[i])
	{
		colour = ft_strsplit(data[i], ',');
		if (colour[1])
			node->colour[i] = ft_atoibase(colour[1] + 2, 16);
		else
			node->colour[i] = 0x000000;
		node->xz[i] = ft_atoi(*colour);
		i++;
	}
	return (node);
}

t_line	*parse_map(char *file)
{
	int		fd;
	int		y;
	char	*line;
	t_line	*mat;
	t_line	*node;

	fd = open(file, O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!y)
		{
			mat = (t_line *)malloc(sizeof(t_line));
			mat = lst_fill(mat, line);
			mat->max_w = mat->length;
			node = (t_line *)malloc(sizeof(t_line));
			mat->next = node;
			node = mat;
		}
		else
		{
			node = node->next;
			node = lst_fill(node, line);
			node->next = (t_line *)malloc(sizeof(t_line));
			if (node->length > mat->max_w)
				mat->max_w = node->length;
		}
		free(line);
		y++;
	}
	(mat) ? mat->max_h = y : 0;
	node = mat;
	while (--y > 0)
		node = node->next;
	node->next = NULL;
	return (mat);
}