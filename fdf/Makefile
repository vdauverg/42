# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 19:22:17 by vdauverg          #+#    #+#              #
#    Updated: 2019/09/23 20:31:42 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFILES = fdf.c parser.c points_math.c draw.c key_press.c key_press2.c

LIBS = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit libft/libft.a

FLAGS = -Wall -Werror -Wextra

all:
	@make -C libft
	@make -sC minilibx_macos
	@gcc $(FLAGS) $(CFILES) $(LIBS) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx_macos

fclean:
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all