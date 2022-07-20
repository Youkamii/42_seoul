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

NAME = libftprintf.a
LIBFT = libft
LIBFT_a = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -c
RM = rm -f
AR = ar
CRS = crs

SRCS	= ft_printf.c	\
		  ft_putchar.c	\
		  ft_strlen.c	\
		  ft_printf_parts.c	\
		  main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
		make all -C $(LIBFT)/
		cp $(LIBFT)/$(LIBFT_a) $(NAME)
		$(AR) $(CRS) $@ $(OBJS)

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean: clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean all clean re