# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarias-i <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 19:16:48 by jarias-i          #+#    #+#              #
#    Updated: 2024/01/09 19:20:59 by jarias-i         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c \
	ft_print_cs.c \
	ft_printnum.c \
	ft_print_unsigned.c \
	ft_print_ptr.c \
	ft_print_hex.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo Archivos eliminados
	@$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean 
