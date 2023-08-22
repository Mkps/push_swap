# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aloubier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 12:58:01 by aloubier          #+#    #+#              #
#    Updated: 2023/08/22 15:13:42 by aloubier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
SRCDIR = ./src
OBJ_DIR = ./build
INCDIR = ./includes

SRC =  $(SRCDIR)/sort/sort.c $(SRCDIR)/sort/sort_extend.c \
$(SRCDIR)/operations/pushswap.c $(SRCDIR)/operations/do_operation.c $(SRCDIR)/operations/rotate.c \
$(SRCDIR)/utils/median.c $(SRCDIR)/utils/minmax.c \
$(SRCDIR)/utils/parsing.c $(SRCDIR)/utils/init.c $(SRCDIR)/utils/output.c \
$(SRCDIR)/utils/exit.c $(SRCDIR)/utils/stack_check.c $(SRCDIR)/sort/sort_operations.c \
$(SRCDIR)/utils/libft/ft_atoi.c $(SRCDIR)/utils/libft/ft_lstadd_back.c $(SRCDIR)/utils/libft/ft_lstadd_front.c \
$(SRCDIR)/utils/libft/ft_lstclear.c $(SRCDIR)/utils/libft/ft_lstdelone.c $(SRCDIR)/utils/libft/ft_lstlast.c \
$(SRCDIR)/utils/libft/ft_lstsize.c $(SRCDIR)/utils/libft/ft_split.c $(SRCDIR)/utils/libft/ft_strcmp.c \
$(SRCDIR)/utils/libft/ft_lstnew.c $(SRCDIR)/utils/libft/ft_abs.c

MAIN_SRC = $(SRCDIR)/sort/main.c

BNS_SRC = $(SRCDIR)/checker/main.c $(SRCDIR)/checker/checker.c $(SRCDIR)/checker/get_next_line.c $(SRCDIR)/checker/get_next_line_utils.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_MAIN = $(MAIN_SRC:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

OBJ_BONUS = $(BNS_SRC:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	make all -C libft
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) libft/libft.a
	
bonus: $(BONUS)

$(BONUS): $(OBJ) $(OBJ_BONUS)
	make all -C libft
	$(CC) -o $(BONUS) $(OBJ) $(OBJ_BONUS) libft/libft.a

$(OBJ_DIR)/%.o:	$(SRCDIR)/%.c
	mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
