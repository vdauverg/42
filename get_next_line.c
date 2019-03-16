/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:26:59 by vdauverg          #+#    #+#             */
/*   Updated: 2019/03/16 01:27:11 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_stroffcpy(char *dst, const char *src)
{
	char	*tmp;
	int		offset;
	int		len;

	offset = ft_strlen(src);
	len = ft_strlen(dst);
	tmp = (char *)malloc(len + 1);
	tmp = ft_strncpy(tmp, src, offset);
	ft_strncpy(tmp + offset, dst, len - offset);
	tmp[len] = '\0';
	dst = ft_strcpy(dst, tmp);
	free(tmp);
	return (offset);
}

static void	ft_lsttostr(char *str, t_list *lst)
{
	int		len;
	int		offset;
	t_list	*curr;

	len = 0;
	offset = 0;
	curr = lst;
	while (curr)
	{
		len += curr -> content_size;
		curr = curr -> next;
	}
	str = (char *)malloc(len + 1);
	str[len] = '\0';
	while (lst)
	{
		ft_strcpy(str + offset, lst -> content);
		offset += lst -> content_size;
		lst = lst -> next;
	}
}

int			get_next_line(const int fd, char **line)
{
	int 		isRead;
	int			i;
	static char	*lMem;
	t_list		*head;
	t_list		*curr;

	if (!line)
		return (-1);
	if ((*line = (char *)malloc(BUFF_SIZE + 1)))
	{
		while (!lMem && !*lMem)
		{
			isRead = read(fd, *line, BUFF_SIZE);
			if (isRead == 0)
				return (0);
			else if (isRead > 0)
			{
				if (lMem && *lMem)
				{
					i = ft_stroffcpy(*line, lMem);
					free(lMem);
				}
				i = 0;
				while ((*line)[i] && (*line)[i] != '\n')
					i++;
				if ((*line)[i] == '\n' && (*line)[i + 1])
					lMem = ft_strdup((*line) + i + 1);
				(*line)[i] = '\0';
			}
			if (!head)
			{
				head = ft_lstnew(*line, i);
				curr = head;
			}
			else
			{
				curr -> next = ft_lstnew(*line, i);
				curr = curr -> next;
			}
			free(*line);
		}
		ft_lsttostr(*line, head);
		return (1);
	}
	return (-1);
}
