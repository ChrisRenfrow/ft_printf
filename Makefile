# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 00:34:03 by crenfrow          #+#    #+#              #
#    Updated: 2017/01/02 00:34:16 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

FILENAMES	= ft_printf ft_vasprintf
CFILES		= $(addsuffix .c, $(FILENAMES))
SOURCES		= $(addprefix src/, $(CFILES))
BUILD		= $(addprefix build/, $(CFILES.c=.o))
INCDIR		= -I includes/ -I libft/includes/
FLAGS		= -Wall -Wextra -Werror
CC			= clang

all: $(NAME)

$(NAME): $(SOURCES) | $(BUILD)
	ar rcs $@ $(BUILD)

build/%.o: src/%.c | build
	$(CC) $(FLAGS) $(INCDIR) -c $^ -o $@

clean:
	rm -rf build/

fclean: clean
	rm -rf $(NAME)

re: fclean all

build:
	mkdir build/

.PHONY: all clean fclean re
