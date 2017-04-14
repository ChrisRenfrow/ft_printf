# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 00:06:49 by crenfrow          #+#    #+#              #
#    Updated: 2017/04/13 16:40:58 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FILENAMES 	= ft_printf
BUILD		= $(addsuffix .o, $(addprefix build/, $(FILENAMES)))
INCDIR		= -I inc/ -I lib/libft/includes
FLAGS		= -Wall -Wextra -Werror
CC			= clang

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build/

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean $(NAME)

$(NAME): $(BUILD)
	libtool -o $@ $<

build/%.o: src/%.c
	@mkdir -p build/
	$(CC) $(FLAGS) $(INCDIR) -c $^ -o $@
