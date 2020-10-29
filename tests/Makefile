# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/18 23:44:50 by awoimbee          #+#    #+#              #
#    Updated: 2020/10/29 14:44:11 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft_tests

CC	=	gcc

CFLAGS = -Wall -Wextra -fno-builtin -march=native

SRC = $(shell cd src && find . -type f -name "*.c")
OBJ = $(addprefix obj/, $(SRC:.c=.o))
OBJ_FOLDERS = $(addprefix obj/, $(shell cd src && find . -type d -not \( -path './obj' -o -path './obj/*' \)))

CFLAGS += -MMD -I./src -I../
LDFLAGS = -L../
LDLIBS = `pkg-config --cflags --libs check` -lft

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
#####################################  RULES  ##################################

all	: $(NAME)

run :
	./$(NAME)

$(NAME)	: ../libft.a $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)Done !$(EOC)\n"

#add rules written by -MMD, the '-' makes it continue even if file doesnt exist
-include $(OBJ:.o=.d)

obj/%.o: src/%.c | $(OBJ_FOLDERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_FOLDERS):
	mkdir -p $(OBJ_FOLDERS)

../libft.a:
	@printf "Missing libft, compiling...\n"
	@$(MAKE) --no-print-directory -C ../ fast

clean	:
	rm -rf ./obj
	@printf "$(RED)objs cleaned$(EOC)\n"

fclean	:	clean
	@rm -f $(NAME)
	@printf "\033[0;31m$(NAME) removed$(EOC)\n"

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC)

.PHONY: all fast so clean fclean re flowchart run

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
