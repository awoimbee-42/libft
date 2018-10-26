# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/10/26 11:56:09 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS	=	$(wildcard srcs/libc/*.c)		\
			$(wildcard srcs/lib42/*.c)		\
			$(wildcard srcs/liblst/*.c)

HEADERS =	./incs

OBJS = $(notdir $(SRCS:.c=.o))

all	:
	@make $(NAME)

optimize :
	$(CC) $(FLAGS) -O3 -c $(SRCS) -I $(HEADERS)
	@mkdir ./objs
	@mv $(OBJS) ./objs
	ar -cvq $(NAME) $(addprefix objs/, $(OBJS))

$(NAME)	:
	$(CC) $(FLAGS) -c $(SRCS) -I $(HEADERS)
	@mkdir ./objs
	@mv $(OBJS) ./objs
	ar -cvq $(NAME) $(addprefix objs/, $(OBJS))

clean	:
	rm -rf ./objs

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all
