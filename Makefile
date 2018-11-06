# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/11/06 14:56:44 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

BONUSFLAGS = -Wconversion -Wno-unused-result -O3

SRCS	=	$(wildcard srcs/libc/*.c)		\
			$(wildcard srcs/lib42/*.c)		\
			$(wildcard srcs/liblst/*.c)

HEADERS =	./

OBJS = $(notdir $(SRCS:.c=.o))

.PHONY: all $(NAME) so clean fclean re


all	:
	@make $(NAME)

$(NAME)	:
	@echo "$(CC) compiling with $(FLAGS)..."
	@$(CC) $(FLAGS) $(BONUSFLAGS) -c $(SRCS) -I $(HEADERS)
	@mkdir ./objs
	@mv $(OBJS) ./objs
	@ar -rcs $(NAME) $(addprefix objs/, $(OBJS))

so	: all
	gcc $(addprefix objs/, $(OBJS)) -shared -o $(NAME:.a=.so)

clean	:
	@echo "cleaning objects..."
	@rm -rf ./objs
	@rm -f $(OBJS)

fclean	:	clean
	@rm -f $(NAME)

re	:	fclean all
