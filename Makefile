# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/03/06 16:20:41 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# MAKEFILE NEEDS FIX #

NAME = libftprintf.a
SRCS = libftprintf prefix utilities utilities_2 printer put_flags #main
MORO = libftprintf prefix utilities utilities_2 printer main put_flags
OG = libftprintf prefix utilities utilities_2 printer main_og put_flags
FLAGS = -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
INCLUDES = -I../libft/
LIB = -L../libft/ -lft

all: $(NAME)

$(NAME):$(addsuffix .c, $(SRCS)) main.c
	gcc -c $(addsuffix .c, $(SRCS)) $(LIB) $(INCLUDES)
	cp ../libft/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(addsuffix .o, $(SRCS))

m:
	@gcc -g $(addsuffix .c, $(MORO)) -L../libft/ -lft -I../libft/
	@./a.out
o:
	gcc -g $(addsuffix .c, $(OG)) -L../libft/ -lft -I../libft/

clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all
