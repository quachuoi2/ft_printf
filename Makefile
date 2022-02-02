# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/02/02 14:28:00 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# MAKEFILE NEEDS FIX #

NAME = libftprintf.a
SRCS = libftprintf main prefix utilities
FLAGS = -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
INCLUDES = -I../libft/includes
LIB = -L../libft/ -lft

all: $(NAME)

$(NAME):
	@gcc $(addsuffix .c, $(SRCS)) $(LIB) $(INCLUDES)

clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all
