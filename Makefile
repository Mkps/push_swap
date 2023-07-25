# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alx <alx@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/07/25 09:54:40 by alx              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BNS = checker_bonus
SRCDIR = ./src
INCDIR = ./includes

SRC = $(SRCDIR)/sort/sort.c $(SRCDIR)/sort/sort_extend.c \
$(SRCDIR)/operations/pushswap.c $(SRCDIR)/operations/do_operation.c $(SRCDIR)/operations/rotate.c \
$(SRCDIR)/utils/median.c $(SRCDIR)/utils/minmax.c \
$(SRCDIR)/utils/parsing.c $(SRCDIR)/utils/init.c $(SRCDIR)/utils/output.c \
$(SRCDIR)/utils/exit.c $(SRCDIR)/utils/stack_check.c $(SRCDIR)/sort/sort_operations.c \
./src/utils/libft/ft_atoi.c ./src/utils/libft/ft_lstadd_back.c ./src/utils/libft/ft_lstadd_front.c \
./src/utils/libft/ft_lstclear.c ./src/utils/libft/ft_lstdelone.c ./src/utils/libft/ft_lstlast.c \
./src/utils/libft/ft_lstsize.c ./src/utils/libft/ft_split.c ./src/utils/libft/ft_strcmp.c \
./src/utils/libft/ft_lstnew.c $(SRCDIR)/utils/libft/ft_abs.c

SORT_SRC = $(SRCDIR)/sort/main.c

BNS_SRC = $(SRCDIR)/checker/main.c

OBJ = $(SRC:%.c= %.o)

OBJ_SORT = $(SORT_SRC:%.c=%.o)

OBJ_BNS = $(BNS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_SORT)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_SORT)
$(NAME_BNS): $(OBJ) $(OBJ_BNS)
	$(CC) -o $(NAME_BNS) $(OBJ) $(OBJ_BNS) 

.c.o:
	$(CC) -c $(CFLAGS) -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJ) $(OBJ_SORT) $(OBJ_BNS)

fclean: clean
	rm -f $(NAME) $(NAME_BNS)
bonus: $(NAME_BNS)

re: fclean all

.PHONY: all bonus clean fclean re
