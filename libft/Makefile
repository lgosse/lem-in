# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:35:12 by lgosse            #+#    #+#              #
#    Updated: 2016/04/27 15:41:23 by lgosse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_NAME =		ft_atoi.c \
				ft_bzero.c \
				ft_get_nb_length.c \
				ft_isalnum.c \
				ft_strisalnum.c \
				ft_isalpha.c \
				ft_strisalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_strisdigit.c \
				ft_isprint.c \
				ft_strisint.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_ltoa_base.c \
				ft_ultoa_base.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strequ.c \
				ft_striter.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strtrim.c \
				ft_strsub.c \
				ft_strstr.c \
				ft_strsplit.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strnew.c \
				ft_strnequ.c \
				ft_strncpy.c \
				ft_strncmp.c \
				ft_strncat.c \
				ft_strmapi.c \
				ft_strmap.c \
				ft_strlen.c \
				ft_strlcat.c \
				ft_strjoin.c \
				ft_strjoin_n_free.c \
				ft_striteri.c \
				ft_lstnew.c \
				ft_lstmap.c \
				ft_lstiter.c \
				ft_lstdelone.c \
				ft_lstadd.c \
				ft_tabdel.c \
				ft_puttab.c \
				ft_realloc_char.c \
				ft_iswhitespace.c \
				ft_linelen.c \
				ft_realloc.c \
				get_next_line.c \
				ft_strupcase.c \
				ft_getattributes.c \
				ft_getinstr.c \
				ft_getnb.c \
				ft_init.c \
				ft_printf.c \
				ft_size_t_itoa_base.c \
				ft_treatattributes.c \
				ft_treatchar.c \
				ft_treatsignednb.c \
				ft_treatstr.c \
				ft_treatunsignednb.c \
				ft_treatwchar.c \
				ft_tabstrdup.c \
				ft_swap.c \
				ft_abs.c \
				ft_lstaddtail.c \
				ft_pow.c \
				ft_parse.c \
				ft_parse_file.c \
				ft_checkstr.c \
				ft_nbrsplit.c \
				ft_lstdup.c \
				ft_swap_int.c \
				ft_lstdelfirst.c \
				ft_wordlen.c \
				ft_strnchr.c \
				ft_strndup.c \
				ft_lstdelbyfunc.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = libft.a

SRC_PATH = src/
LIB_PATH = includes/
OBJ_PATH = obj/

SRC_LIB = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH))

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

all:$(NAME)

$(NAME):$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $(LIB) -o $@ -c $<

clean:
	@rm -rfv $(OBJ)
	@rm -rfv $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all
