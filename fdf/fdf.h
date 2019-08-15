/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincent <vincent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 10:50:12 by vincent           #+#    #+#             */
/*   Updated: 2019/08/14 18:27:45 by vincent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H
# include	"minilibx_macos/mlx.h"
# include	"libft/get_next_line.h"
# include	<stdlib.h>
# include	<math.h>

typedef struct	s_line
{
	int				max_w;
	int				max_h;
	int				length;
	int				*xz;
	unsigned int	*colour;
	struct s_line	*next;
}				t_line;

typedef struct	s_image
{
	int		coldep;
	int		w;
	int		endian;
	char	*image;
	void	*img_ptr;
}				t_image;

t_line			*parse_map(char *file);
# endif
