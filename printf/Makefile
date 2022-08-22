NAME = libftprintf.a

CC = gcc
CFLAG = -Wall -Wextra -Werror

AR = ar
ARFLAGS = crs

INCLUDES = ./libft.h

SRCS	= ft_printf.c	\
		  ft_putchar.c	\
		  ft_strlen.c	\
		  ft_printf_parts.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

fclean : clean
	rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

re : fclean all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : re fclean clean all