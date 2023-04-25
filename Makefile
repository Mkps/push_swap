# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/04/24 14:25:44 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src
INCDIR = ./includes

SRC = $(SRCDIR)/main.c $(SRCDIR)/pushswap.c $(SRCDIR)/rotate.c
OBJ = $(SRC:%.c= %.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
