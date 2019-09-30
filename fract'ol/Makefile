# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 19:22:17 by vdauverg          #+#    #+#              #
#    Updated: 2019/09/29 19:29:15 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFILES = fractol.c display.c equations.c hooks.c

LIBS = minilibx_macos/libmlx.a -framework OpenGL -framework AppKit libft/libft.a

FLAGS = -Wall -Werror -Wextra

all:
	@make -C libft
	@make -C minilibx_macos
	@gcc $(FLAGS) $(CFILES) $(LIBS) -o $(NAME)

clean:
	@make clean -sC libft
	@make clean -C minilibx_macos

fclean: clean
	@rm -f $(NAME)

re: fclean all