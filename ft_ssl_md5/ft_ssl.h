/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:05:03 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/20 20:34:36 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "libft/libft.h"

# define A = [1, 35, 69, 103]
typedef struct	s_metadata
{
	int	flags[4];
}				t_metadata;


char			**read_files(int count, char **files);
char			*read_file(char *file);
char			*md5(char *str, t_metadata meta);
char			*sha256(char *str, t_metadata meta);
char			*sha512(char *str, t_metadata meta);

#endif
