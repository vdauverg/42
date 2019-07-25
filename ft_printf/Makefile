# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/30 13:30:38 by vdauverg          #+#    #+#              #
#    Updated: 2019/07/19 14:20:32 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFILES = ft_printf.c flag_handlers.c specifier_handlers.c helpers.c

OFILES = ft_printf.o flag_handlers.o specifier_handlers.o helpers.o

OBJS = objs

FLAGS = -Wall -Werror -Wextra -I ft_printf.h -I libft/libft.h -c


all: $(NAME)

$(NAME): $(OFILES)
	mkdir $(OBJS)
	cp libft/*.o $(OBJS)/
	mv *.o $(OBJS)/
	ar rc $(NAME) $(OBJS)/*.o

$(OFILES): $(CFILES)
	gcc $(FLAGS) $(CFILES)

cleanobjs:
	rm -rf $(OBJS)

clean: cleanobjs
	rm -rf $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all