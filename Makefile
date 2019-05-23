# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 11:55:20 by awoimbee          #+#    #+#              #
#    Updated: 2019/05/22 16:36:33 by awoimbee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	=	gcc

CFLAGS = -march=native -Wall -Wextra -Werror -Ofast -fno-builtin -ftree-vectorize -fstrict-aliasing

SRCS_CHAR =	ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
			ft_isalpha.c		ft_isdigit.c		ft_tolower.c		\
			ft_toupper.c

SRCS_FD =	ft_putchar.c		ft_putendl_fd.c		ft_putstr.c			\
			ft_putchar_fd.c		ft_putnbr.c			ft_putstr_fd.c		\
			ft_putendl.c		ft_putnbr_fd.c		get_next_line.c

SRCS_MEM =	ft_bzero.c			ft_memchr.c			ft_memdel.c			\
			ft_memalloc.c		ft_memcmp.c			ft_memmove.c		\
			ft_memccpy.c		ft_memcpy.c			ft_memset.c			\
			ft_mempcpy.c		ft_memnset.c		ft_memfree.c

SRCS_NB =	ft_abs.c			ft_atoi.c			ft_itoa.c			\
			ft_atoi_base.c		ft_itoa_base.c		ft_swap_int.c		\
			ft_atof.c			ft_atof_mv.c		ft_atoi_mv.c

SRCS_STR =	ft_stpcpy.c			ft_striter.c		ft_strncpy.c		\
			ft_strcat.c			ft_striteri.c		ft_strnequ.c		\
			ft_strcat_join.c	ft_strjoin.c		ft_strnew.c			\
			ft_strchr.c			ft_strlcat.c		ft_strnstr.c		\
			ft_strclr.c			ft_strlen.c			ft_strrchr.c		\
			ft_strcmp.c			ft_strmap.c			ft_strrev.c			\
			ft_strcpy.c			ft_strmapi.c		ft_strsplit.c		\
			ft_strdel.c			ft_strncat.c		ft_strstr.c			\
			ft_strdup.c			ft_strncat_join.c	ft_strsub.c			\
			ft_strequ.c			ft_strncmp.c		ft_strtrim.c		\
			ft_strndup.c

SRCS_PRTF =	fill_arg_struct.c	s_itoa_base.c		sub_hub.c			\
			ft_flag_cs.c		ft_vprintf.c		text_decoration.c	\
			ft_flag_f.c			join_arg.c			u_itoa_base.c		\
			ft_flag_r.c			lib0.c				ft_printf.c

SRCS_LST =	ft_lstadd.c			ft_lstdelone.c		ft_lstmap.c			\
			ft_lst_at.c			ft_lst_free_link.c	ft_lstnew.c			\
			ft_lstdel.c			ft_lstiter.c		ft_lst_push_back.c

SRCS_QUE =	create_destroy.c	disp.c				isempty.c			\
			push_pop.c			realloc.c			flush.c

SRCS_VEC4 =	vec4_new.c			vec4_newa.c			vec4_div.c			\
			vec4_add_sub.c		vec4_mul.c			vec4_abs_sqr.c		\
			vec4_dot.c			vec4_mod.c								\
			vec4_cross.c		vec4_mat.c

SRCS_VECT =	new.c				push.c				realloc.c			\
			vector_map.c		vector_del_at.c

SRCS_GARB =	gb_fail.c			gb_add.c			gb_defrag.c			\
			gb_free.c			gb_freeall.c		gb_init.c			\
			gb_malloc.c			gb_remove.c			gb_memalloc.c		\
			gb_init_existing.c	gb_realloc.c		intrin_gb_extend.c

SRCS_OTHER = msg_exit.c

SRCS_NAME =	$(addprefix libchar/, $(SRCS_CHAR))		\
			$(addprefix libfd/,   $(SRCS_FD))		\
			$(addprefix libmem/,  $(SRCS_MEM))		\
			$(addprefix libnb/,   $(SRCS_NB))		\
			$(addprefix libstr/,  $(SRCS_STR))		\
			$(addprefix ft_prtf/, $(SRCS_PRTF))		\
			$(addprefix t_lst/,   $(SRCS_LST))		\
			$(addprefix t_queue/, $(SRCS_QUE))		\
			$(addprefix t_vector/, $(SRCS_VECT))	\
			$(addprefix t_garbage/, $(SRCS_GARB))	\
			$(SRCS_OTHER)
OBJ_NAME = $(SRCS_NAME:.c=.o)

SRC_PATH = src
OBJ_PATH = obj
OBJ_DIRS = libchar libfd libmem libnb libstr ft_prtf t_lst t_queue t_vec4 t_vector t_garbage

################################################################################
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I./

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -Wno-unused-result
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME)

fast :
	@make -s -j$(NUMPROC)

libft.gen :
	@printf "$(foreach cfile,$(SRCS_VEC4),$(addprefix # include \"src/t_vec4/,$(addsuffix \"\n,$(cfile))))" > libft.gen

$(OBJ_PATH)	:
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@mkdir -p $(addprefix $(OBJ_PATH)/, $(OBJ_DIRS)) 2> /dev/null
	@printf "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME)	: libft.gen $(OBJS)
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	@ar -rcs $(NAME) $(OBJS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%-50s\r" "$(CC) $@"
	@$(CC) $(CFLAGS) -o $@ -c $<

so	: all
	@printf "$(CC) (...) -shared -o $(NAME:.a=.so)\n"
	@$(CC) $(OBJS) -shared -o $(NAME:.a=.so)

clean	:
	@rm -rf $(OBJ_PATH)
	@printf "$(RED)./$(OBJ_PATH) cleaned$(EOC)\n"

fclean	:	clean
	@rm -f libft.gen
	@rm -f $(NAME)
	@rm -f $(NAME:.a=.so)
	@printf "\033[0;31m$(NAME), $(NAME:.a=.so) and libft.gen removed$(EOC)\n"

re	:	fclean
	@make -s -j$(NUMPROC)

flowchart:
	@printf "%s\n"	\
	"drive.google.com/file/d/1WmQpjdGgEPmhxpchUW6tD26C3euBPtcL/view?usp=sharing"

.PHONY: all fast so clean fclean re flowchart

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
