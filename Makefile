# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/11/14 10:54:47 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC = gcc

SRCS	=	$(wildcard srcs/libc/*.c)		\
			$(wildcard srcs/lib42/*.c)		\
			$(wildcard srcs/liblst/*.c)

INC_DIR =	./

CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Wno-unused-result #-Wconversion -O3
endif

CFLAGS += -I$(INC_DIR)

OBJS = $(SRCS:.c=.o)

all	:
	@make $(NAME)

$(NAME)	: $(OBJS)
	@echo "ar -rs $(NAME) objects..."
	@ar -rs $(NAME) $(OBJS)

so	: all
	gcc $(addprefix objs/, $(OBJS)) -shared -o $(NAME:.a=.so)

clean	:
	@echo "cleaning objects..."
	@rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: all so clean fclean re
