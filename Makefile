# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 16:47:05 by lgosse            #+#    #+#              #
#    Updated: 2016/05/13 16:53:34 by lgosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	lem_in.c \
			lemininit.c \
			lemininit2.c \
			checkfmt.c \
			predicate.c \
			treatcommands.c \
			getpipes.c \
			algolemin.c \
			getrooms.c \
			invaliduselessways.c \
			ft_findpath.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = lem-in

SRC_PATH = src/
LIB_PATH = libft/includes/
OBJ_PATH = obj/

SRC_LIB = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -g
LDFLAGS = -Llibft
LDLIBS = -lft

SRC_MMKR =	mapmaker.c \
			hooksmmkr.c \
			handlegrid.c \
			rabdinit.c \
			applyroom.c \
			handlepipes.c \
			pipesthesequel.c \
			print.c \
			printtoimg.c

NAME_MMKR = $(SRC_MMKR:.c=.o)
MMKR_PATH = srcmapmaker/

LIB_MMKR = $(addprefix $(SRC_MMKR),$(NAME_MMKR))
OBJ_MMKR = $(addprefix $(OBJ_PATH),$(NAME_MMKR))

SRC_VISU =	initgrid.c \
			initmlxvisu.c \
			printfunctions.c \
			visu.c \
			pipes.c \
			drawants.c \
			hooks.c \
			setants.c \
			predicate2.c \
			wait.c \
			placeant.c

NAME_VISU = $(SRC_VISU:.c=.o) \
			lemininit.o \
			lemininit2.o \
			checkfmt.o \
			predicate.o \
			treatcommands.o \
			getpipes.o \
			algolemin.o \
			getrooms.o \
			invaliduselessways.o \
			ft_findpath.o

VISU_PATH = srcvisu/

LIB_VISU = $(addprefix $(SRC_VISU),$(NAME_VISU))
OBJ_VISU = $(addprefix $(OBJ_PATH),$(NAME_VISU))

all:$(NAME) mmkr visu

$(NAME):$(OBJ)
	make -C libft/ -j 8
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "\033[32mCompilation done !\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

mmkr:$(OBJ_MMKR)
	make -C libft/ -j 8
	@$(CC) $(LDFLAGS) -lmlx -framework OpenGL -framework AppKit $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o:$(MMKR_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

visu:$(OBJ_VISU)
	make -C libft/ -j 8
	@$(CC) $(LDFLAGS) -lmlx -framework OpenGL -framework AppKit $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o:$(VISU_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

clean:
	@echo "\033[31mCleaned following files :\033[0m"
	@make -C libft/ clean
	@rm -fv $(OBJ)
	@rm -rfv $(OBJ_PATH)
	@echo "\033[32mClean objects done !\033[0m"

fclean: clean
	@rm -fv $(NAME)
	@rm -fv mmkr
	@rm -fv visu
	@echo "\033[32mClean executable done !\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
