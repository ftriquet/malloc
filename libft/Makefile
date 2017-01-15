# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 08:35:37 by ftriquet          #+#    #+#              #
#    Updated: 2016/06/03 00:12:25 by ftriquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_atoi.c \
		   ft_itoa.c \
		   ft_nbr_len.c \
		   ft_error.c

SRC_NAME += boolean/ft_isalnum.c \
			boolean/ft_isalpha.c \
			boolean/ft_isascii.c \
			boolean/ft_isblank.c \
			boolean/ft_isdigit.c \
			boolean/ft_islower.c \
			boolean/ft_isnumber.c \
			boolean/ft_isprint.c \
			boolean/ft_isupper.c

SRC_NAME += display/ft_putchar.c \
			display/ft_putchar_fd.c \
			display/ft_putendl.c \
			display/ft_putendl_fd.c \
			display/ft_putnbr.c \
			display/ft_putnbr_fd.c \
			display/ft_putstr.c \
			display/ft_putstr_fd.c

SRC_NAME += ft_printf/buffer.c \
			ft_printf/fill_flags.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_printf_c.c \
			ft_printf/ft_printf_s.c \
			ft_printf/printf_color.c \
			ft_printf/printf_di.c \
			ft_printf/printf_divs.c \
			ft_printf/printf_s_utils.c \
			ft_printf/printf_u.c \
			ft_printf/printf_wchar.c

SRC_NAME += lists/ft_list_add.c \
			lists/ft_list_cells.c \
			lists/ft_list_init.c \
			lists/ft_list_iter.c \
			lists/ft_list_remove.c \
			lists/ft_list_get.c \
			lists/ft_list_map.c

SRC_NAME += mem/ft_bzero.c \
			mem/ft_memalloc.c \
			mem/ft_memccpy.c \
			mem/ft_memchr.c \
			mem/ft_memcmp.c \
			mem/ft_memcpy.c \
			mem/ft_memdel.c \
			mem/ft_memdup.c \
			mem/ft_memmove.c \
			mem/ft_memset.c

SRC_NAME += strings/ft_empty_string.c \
			strings/ft_freetab.c \
			strings/ft_get_index.c \
			strings/ft_match.c \
			strings/ft_str_replace.c \
			strings/ft_strcat.c \
			strings/ft_strchr.c \
			strings/ft_strclr.c \
			strings/ft_strcmp.c \
			strings/ft_strcpy.c \
			strings/ft_strdel.c \
			strings/ft_strdup.c \
			strings/ft_strequ.c \
			strings/ft_striter.c \
			strings/ft_striteri.c \
			strings/ft_strjoin.c \
			strings/ft_strlcat.c \
			strings/ft_strlen.c \
			strings/ft_strmap.c \
			strings/ft_strmapi.c \
			strings/ft_strncat.c \
			strings/ft_strncmp.c \
			strings/ft_strncpy.c \
			strings/ft_strnequ.c \
			strings/ft_strnew.c \
			strings/ft_strnlen.c \
			strings/ft_strnstr.c \
			strings/ft_strrchr.c \
			strings/ft_strreplace.c \
			strings/ft_strsplit.c \
			strings/ft_strstr.c \
			strings/ft_strsub.c \
			strings/ft_strsubptr.c \
			strings/ft_strtrim.c \
			strings/ft_tabsize.c \
			strings/ft_tolower.c \
			strings/ft_toupper.c \
			strings/ft_trim.c \
			strings/ft_tablen.c \
			strings/get_next_line.c

SRC_NAME += slices/slices.c \
			slices/slices_utils.c \
			slices/slices_sort.c \
			slices/slices_op.c \
			slices/slices_iter.c

SYSTEM = $(shell uname -s)
ifeq ($(SYSTEM),Darwin)
	SRC_NAME += mlx/image.c
endif

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g

INC_PATH = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p ./obj/{ft_printf,strings,boolean,display,lists,mem,slices,mlx}
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

clean:
	rm -rf ./obj

fclean:clean
	rm -f $(NAME)

re:fclean all


.PHONY: all clean fclean re
