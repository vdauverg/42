# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:10:49 by vdauverg          #+#    #+#              #
#    Updated: 2020/08/24 15:55:04 by vdauverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SDIR = ./src
ODIR = ./objs

_SRCS = *.c
_OBJS = *.o

SRCS = $(SDIR)/*.c
OBJS = $(ODIR)/*.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(ODIR) $(SRCS)
	gcc $(FLAGS) -c $(SRCS) -I *.h
	mv $(_OBJS) $(ODIR)

$(ODIR):
	mkdir $(ODIR)

clean:
	rm -rf $(OBJS)
	rm -rf $(ODIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all
