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

NAME	= libftprintf.a

CC		= gcc
CFLAG	= -Wall -Wextra -Werror -D BUFFER_SIZE=42

RM		= rm -f

AR		= ar
ARFLAGS	= crs

INCLUDES	= ./ft_printf.h

SRCS	= ft_printf.c	\
		  ft_putchar.c
		  ft_strlen.c
		  ft_printf_parts.c\

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

 .PHONY : all clean fclean re
