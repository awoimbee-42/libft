# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/11 02:28:35 by awoimbee          #+#    #+#              #
#    Updated: 2018/11/11 03:06:28 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	tests

CC	=	gcc

FLAGS = -W

SRCS	=	$(wildcard *.c)	\
			../libft.a

HEADERS	=	./


all	:	$(NAME)

$(NAME)	:
	#@make -C ../
	$(CC) $(FLAGS) $(SRCS) -I $(HEADERS) -o $(NAME)

clean	:
	@echo "cleaning objects..."

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

.PHONY: all so clean fclean re