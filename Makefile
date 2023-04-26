# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/04/25 17:53:04 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src
INCDIR = ./includes

<<<<<<< HEAD
SRC = $(SRCDIR)/main.c $(SRCDIR)/pushswap.c $(SRCDIR)/rotate.c $(SRCDIR)/parsing.c
=======
SRC = $(SRCDIR)/main.c $(SRCDIR)/operations/pushswap.c $(SRCDIR)/operations/rotate.c $(SRCDIR)/utils/parsing.c $(SRCDIR)/utils/init.c
>>>>>>> 17b16fc8c225969779cfac7896e5da0e0a268f45
OBJ = $(SRC:%.c= %.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
