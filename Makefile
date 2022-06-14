# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 10:35:47 by qnguyen           #+#    #+#              #
#    Updated: 2022/06/14 18:59:21 by qnguyen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
SRCS = libftprintf prefix utilities utilities_2 printer flags_handler\
conversion_prefix_adapter
FLAGS = -Wall -Wextra -Werror
NITPICK = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
LIB_DIR = libft/
LIB = -lft

all: $(NAME)

$(NAME): $(addsuffix .c, $(SRCS))
	make -C $(LIB_DIR)
	gcc -c $(addsuffix .c, $(SRCS)) $(FLAGS) -I$(LIB_DIR) -O3 #remove -O3 for linux
	mv $(LIB_DIR)libft.a ./$(NAME)
	ar -rcs $(NAME) $(addsuffix .o, $(SRCS))

m:
	@gcc -g $(addsuffix .c, $(SRCS)) main.c -L$(LIB_DIR) $(LIB) -I$(LIB_DIR) #-O3
	@./a.out

clean:
	@/bin/rm -f $(addsuffix .o, $(SRCS))
	@make -C $(LIB_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIB_DIR) fclean
	@/bin/rm -f a.out

re: fclean all
