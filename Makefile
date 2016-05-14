# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 17:19:54 by ftriquet          #+#    #+#              #
#    Updated: 2016/05/14 17:28:55 by ftriquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

LINK_NAME = libft_malloc.so

SRC = src/allocs.c \
	  src/blocks.c \
	  src/safe.c \
	  src/show.c \
	  src/test.c \
	  src/unsafe.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -Werror

LIBFT_INC = -I libft/includes

INC = -I includes

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(CFLAGS) -shared -o $(NAME) $(OBJ) -lft -L libft $(INC) $(LIBFT_INC)
	ln -s $(NAME) $(LINK_NAME)

%.o: %.c
	gcc $(CFLAGS) $(INC) $(LIBFT_INC) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
