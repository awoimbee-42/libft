# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/11/12 18:12:32 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

FLAGS = -Wall -Wextra -Werror

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
			ft_toupper.c

HEADERS	=	./

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	: $(SRCS) libft.h
	@echo "$(CC) compiling with $(FLAGS)..."
	@$(CC) $(FLAGS) -c $(SRCS) -I $(HEADERS)
	@ar -rcs $(NAME) $(OBJS)

clean	:
	@echo "cleaning objects..."
	@rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: all clean fclean re
