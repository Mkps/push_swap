# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/04/26 18:15:26 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCDIR = ./src
INCDIR = ./includes

SRC = $(SRCDIR)/main.c \
$(SRCDIR)/operations/pushswap.c $(SRCDIR)/operations/rotate.c \
$(SRCDIR)/utils/parsing.c $(SRCDIR)/utils/init.c $(SRCDIR)/utils/output.c \
./src/utils/libft/ft_atoi.c ./src/utils/libft/ft_lstadd_back.c ./src/utils/libft/ft_lstadd_front.c \
./src/utils/libft/ft_lstclear.c ./src/utils/libft/ft_lstdelone.c ./src/utils/libft/ft_lstlast.c \
./src/utils/libft/ft_lstsize.c ./src/utils/libft/ft_split.c ./src/utils/libft/ft_strcmp.c

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
