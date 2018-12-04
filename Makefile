# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/12/04 19:10:03 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS = -Wall -Wextra -Werror

SRCS	=	ft_atoi.c			\
			ft_bzero.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_lstadd.c			\
			ft_lstdel.c			\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_memalloc.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memdel.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar.c		\
			ft_putchar_fd.c		\
			ft_putendl.c		\
			ft_putendl_fd.c		\
			ft_putnbr.c			\
			ft_putnbr_fd.c		\
			ft_putstr.c			\
			ft_putstr_fd.c		\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strclr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdel.c			\
			ft_strdup.c			\
			ft_strequ.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlen.c			\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strncat.c		\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strnequ.c		\
			ft_strnew.c			\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strsplit.c		\
			ft_strstr.c			\
			ft_strsub.c			\
			ft_strtrim.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_lst_push_back.c	\
			ft_lst_at.c			\
			ft_lst_free_link.c	\
			ft_swap_int.c		\
			get_next_line.c		\
			ft_atoi_base.c		\
			ft_itoa_base.c		\
			ft_strrev.c			\
			ft_strcat_join.c

OBJS = $(SRCS:.c=.o)

INC_DIR = ./

CFLAGS += -I$(INC_DIR)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Wno-unused-result
endif

OBJS = $(SRCS:.c=.o)


all	:	$(NAME)

$(NAME)	: $(OBJS)
	@echo "ar -rcs $(NAME)..."
	@ar -rcs $(NAME) $(OBJS)

so	: all
	@echo "$(CC) ... -shared -o $(NAME:.a=.so)"
	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	@echo "cleaning objects..."
	@rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	rm -f $(NAME:.a=.so)

re	:	fclean all

.PHONY: all so clean fclean re
