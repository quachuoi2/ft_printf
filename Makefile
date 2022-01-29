# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/01/28 13:55:25 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# MAKEFILE NEEDS FIX #

NAME = libftprintf.a
SRCS = libftprintf main

all: $(NAME)

$(NAME):
	@gcc -g $(addsuffix .c, $(SRCS)) -Llibft/ -lft -Ilibft/
clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all
