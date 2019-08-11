/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 09:15:54 by vincent           #+#    #+#             */
/*   Updated: 2019/08/10 11:43:59 by vincent          ###   ########.fr       */
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
		if (*(colour + 1))
			node->colour[i] = ft_atoibase(colour[1] + 2, 16);
		node->xz[i] = ft_atoi(*colour);
		i++;
	}
	return (node);
}

t_line	*lst_addline(t_line *node, char *line, int y)
{
	node = (t_line *)malloc(sizeof(t_line));
	node = lst_fill(node, line);
	node = node->next;
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
		node = lst_addline((!y) ? mat : node, line, y);
		y++;
	}
	node = NULL;
	return (mat);
}