# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/30 13:30:38 by vdauverg          #+#    #+#              #
#    Updated: 2019/08/12 11:02:32 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = ft_printf.c flag_handlers.c padding_handlers.c helpers.c \
			diouxx_handlers.c ft_ftoa.c ft_itoabase.c conversion_handlers.c \
			conversions.c modifier_handlers.c

OFILES = ft_printf.o flag_handlers.o padding_handlers.o helpers.o \
			diouxx_handlers.o ft_ftoa.o ft_itoabase.o conversion_handlers.o \
			conversions.o modifier_handlers.o

OBJS = objs

FLAGS = -Wall -Werror -Wextra -c

all: $(NAME)

$(NAME): $(OFILES)
	ar rc $(NAME) *.o libft/*.o

$(OFILES): $(CFILES)
	make -C libft
	gcc $(FLAGS) $(CFILES)

clean:
	make fclean -C libft/
	rm -rf $(OFILES)

fclean: clean
	make clean -C libft/
	rm -f $(NAME)

re: fclean all