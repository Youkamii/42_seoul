SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

HEADER	= includes

CC		= gcc

CFLAGS 	= -Wall -Wextra -Werror

LIB		= ranlib

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS} 
		${LIB} ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		all clean fclean re