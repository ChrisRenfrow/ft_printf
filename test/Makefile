# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/13 16:47:51 by crenfrow          #+#    #+#              #
#    Updated: 2017/04/13 16:57:20 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf_test

FILES		= main.c

INCDIR		= -I ../inc/ -I ../lib/libft/includes
LIBS		= -L ../lib/libft/ -lft -L ../ -lftprintf
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

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(FILES) $(INCDIR) $(LIBS) -o $@
