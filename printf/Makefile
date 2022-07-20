# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 21:09:32 by chyeok            #+#    #+#              #
#    Updated: 2022/07/01 21:09:34 by chyeok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCS	= ft_printf.c	\
		  ft_putchar.c	\
		  ft_strlen.c	\
		  ft_printf_parts.c

OBJS=$(SRCS:.c=.o)

NAME=libftprintf.a

HEADER=-I .

CFLAG=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $^

%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re