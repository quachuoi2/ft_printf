# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/02/15 02:18:18 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# MAKEFILE NEEDS FIX #

NAME = libftprintf.a
SRCS = libftprintf prefix utilities print_dif print_cs print_pouxx print_flags #main
MORO = libftprintf prefix utilities print_dif print_cs print_pouxx main print_flags
OG = libftprintf prefix utilities print_dif print_cs print_pouxx main_og print_flags
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
#	gcc main.c -L. -lftprintf -I../libft/

m:
	@gcc -g $(addsuffix .c, $(MORO)) -L../libft/ -lft -I../libft/

o:
	@gcc -g $(addsuffix .c, $(OG)) -L../libft/ -lft -I../libft/

clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f a.out

re: fclean all
