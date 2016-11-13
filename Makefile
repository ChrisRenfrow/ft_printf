# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 22:12:44 by crenfrow          #+#    #+#              #
#    Updated: 2016/11/12 23:48:56 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FILENAMES	= ft_printf
CFILES		= $(addsuffix .c, $(FILENAMES))
SOURCES		= $(addprefix src/, $(CFILES))
BUILD		= $(addprefix build/, $(CFILES.c=.o))
CC			= clang
FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES) | $(BUILD)
	ar rcs $@ $(BUILD)

build/%.o: sources/%.c | build
	$(CC) $(FLAGS) -I includes/ -c $^ -o $@

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)

re: fclean all

build:
	mkdir build/

.PHONY: all clean fclean re
