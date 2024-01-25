# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 09:07:22 by zabdulza          #+#    #+#              #
#    Updated: 2024/01/25 09:07:25 by zabdulza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub
CFLAGS	=
LIBMLX	= ./lib/MLX42
LIBFT	= lib/libft
LIBF	= lib/libft/libft.a
HEADERS = -I./include -I$(LIBMLX)/include -I$(LIBFT)/includes
LDFLAGS = -L /Users/etienneduplessix/.brew/Cellar/glfw/3.3.8/lib
LIBS	= $(LIBMLX)/build/libmlx42.a -lglfw $(LDFLAGS) -ldl -lm -pthread 
SRCS	= $(shell find ./src -iname "*.c")
OBJS_DIR= OBJS
OBJS	= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(LIBS) $(LIBF) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(LIBF)
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
