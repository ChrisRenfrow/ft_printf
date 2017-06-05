# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 00:06:49 by crenfrow          #+#    #+#              #
#    Updated: 2017/06/05 14:51:27 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FILENAMES 	= ft_printf format_conversion
CFILES 		= $(addsuffix .c, $(FILENAMES))
SOURCES		= $(addprefix src/, $(CFILES))
BUILD 		= $(addprefix build/, $(CFILES:.c=.o))
INCDIR		= -I inc/ -I lib/libft/includes
FLAGS		= -Wall -Wextra -Werror
CC			= gcc

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf build/

.PHONY: fclean
fclean: clean
	@make -C lib/libft fclean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(BUILD)
	ar rcs $@ $(BUILD)

build/%.o: src/%.c
	@mkdir -p build/
	@make -C lib/libft
	$(CC) $(FLAGS) $(INCDIR) -c $^ -o $@
