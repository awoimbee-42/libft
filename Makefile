# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/11/13 15:29:57 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

#FLAGS += -Wconversion -O3

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	FLAGS += -Wno-unused-result
endif

SRCS	=	$(wildcard srcs/libc/*.c)		\
			$(wildcard srcs/lib42/*.c)		\
			$(wildcard srcs/liblst/*.c)

HEADERS =	./

OBJS = $(notdir $(SRCS:.c=.o))

all	:
	@make $(NAME)

$(NAME)	: $(SRCS) libft.h
	@echo "$(CC) compiling with $(FLAGS)..."
	@$(CC) $(FLAGS) -c $(SRCS) -I $(HEADERS)
	@mkdir -p ./objs
	@mv -f $(OBJS) ./objs
	@ar -rs $(NAME) $(addprefix objs/, $(OBJS))

so	: all
	gcc $(addprefix objs/, $(OBJS)) -shared -o $(NAME:.a=.so)

clean	:
	@echo "cleaning objects..."
	@rm -rf ./objs
	@rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: all so clean fclean re
