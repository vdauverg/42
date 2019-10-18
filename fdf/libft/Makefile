# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:10:49 by vdauverg          #+#    #+#              #
#    Updated: 2019/09/22 19:02:55 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
C_FILES = *.c
O_FILES = *.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(O_FILES): $(C_FILES)
	gcc $(FLAGS) -c $(C_FILES) -I *.h

clean:
	rm -rf $(O_FILES)

fclean:	clean
	rm -f $(NAME)

re: fclean all
