# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arthur <arthur@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2018/12/16 17:44:16 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_CHAR =	ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
			ft_isalpha.c		ft_isdigit.c		ft_tolower.c		\
			ft_toupper.c

SRCS_FD =	ft_putchar.c		ft_putendl_fd.c		ft_putstr.c			\
			ft_putchar_fd.c		ft_putnbr.c			ft_putstr_fd.c		\
			ft_putendl.c		ft_putnbr_fd.c		get_next_line.c

SRCS_LST =	ft_lstadd.c			ft_lstdelone.c		ft_lstmap.c			\
			ft_lst_at.c			ft_lst_free_link.c	ft_lstnew.c			\
			ft_lstdel.c			ft_lstiter.c		ft_lst_push_back.c

SRCS_MEM =	ft_bzero.c			ft_memchr.c			ft_memdel.c			\
			ft_memalloc.c		ft_memcmp.c			ft_memmove.c		\
			ft_memccpy.c		ft_memcpy.c			ft_memset.c

SRCS_STR =	ft_stpcpy.c			ft_striter.c		ft_strncpy.c		\
			ft_strcat.c			ft_striteri.c		ft_strnequ.c		\
			ft_strcat_join.c	ft_strjoin.c		ft_strnew.c			\
			ft_strchr.c			ft_strlcat.c		ft_strnstr.c		\
			ft_strclr.c			ft_strlen.c			ft_strrchr.c		\
			ft_strcmp.c			ft_strmap.c			ft_strrev.c			\
			ft_strcpy.c			ft_strmapi.c		ft_strsplit.c		\
			ft_strdel.c			ft_strncat.c		ft_strstr.c			\
			ft_strdup.c			ft_strncat_join.c	ft_strsub.c			\
			ft_strequ.c			ft_strncmp.c		ft_strtrim.c

SRCS_NAME =	$(addprefix libchar/, $(SRCS_CHAR))	\
			$(addprefix libfd/, $(SRCS_FD))		\
			$(addprefix liblst/, $(SRCS_LST))	\
			$(addprefix libmem/, $(SRCS_MEM))	\
			$(addprefix libstr/, $(SRCS_STR))
OBJ_NAME = $(SRCS_NAME:.c=.o)

SRC_PATH = src
OBJ_PATH = obj
OBJ_DIRS = libchar libfd liblst libmem libstr

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


CPPFLAGS = -I./

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Wno-unused-result
endif


all	:	$(NAME)

pre-build	:
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(addprefix $(OBJ_PATH)/, $(OBJ_DIRS)) 2> /dev/null
	@echo -e "\033[0;32mMaking libft with \"$(CFLAGS) $(CPPFLAGS)\"...\033[0m"

$(NAME)	: pre-build $(OBJS)
	@echo -e "\033[0;32mcreating $(NAME)...\033[0m"
	@echo -e "\tar -rcs $(NAME) (...)"
	@ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo -e "\t$(CC) (...) $@"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<


so	: all
	@echo "$(CC) (...) -shared -o $(NAME:.a=.so)"
	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	@echo -e "\033[0;31mcleaning objects...\033[0m"
	@echo -e "\trm -rf $(OBJ_PATH)"
	@rm -rf $(OBJ_PATH)

fclean	:	clean
	@echo -e "\033[0;31mcleaning $(NAME), $(NAME:.a=.so)...\033[0m"
	@echo -e "\trm -f $(NAME)\n\trm -f $(NAME:.a=.so)"
	@rm -f $(NAME)
	@rm -f $(NAME:.a=.so)

re	:	fclean all

.PHONY: all so clean fclean re
