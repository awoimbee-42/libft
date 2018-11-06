# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 11:53:00 by qfremeau          #+#    #+#              #
#    Updated: 2015/12/10 12:56:56 by qfremeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
LIB = ../libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC = srcs/main.c srcs/check_part1.c srcs/check_part2.c srcs/check_bonus.c\
	srcs/test_exc.c

test:
	gcc -o $(NAME) $(FLAGS) $(SRC) $(LIB)

clean:
	rm -r $(NAME)

fclean: clean

re: clean test
