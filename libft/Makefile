# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alx <alx@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:37:47 by aloubier          #+#    #+#              #
#    Updated: 2023/07/25 11:42:01 by alx              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_substr.c ft_strdup.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strrchr.c ft_itoa.c ft_strmapi.c ft_striteri.c\
      ft_strjoin.c ft_strtrim.c ft_split.c ft_strchr.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strlcpy.c ft_memmove.c ft_memcpy.c ft_bzero.c \
      ft_memset.c ft_strlen.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strncmp.c ft_freetab.c\
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
	  ft_printf.c ft_printf_hex.c ft_printf_nbr.c ft_printf_ptr.c ft_printf_utils.c

OBJ = $(SRC:%.c= %.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./

all: $(NAME)

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
