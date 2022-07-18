# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 14:21:00 by chyeok            #+#    #+#              #
#    Updated: 2022/05/25 18:16:44 by chyeok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

SRCS					= ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_striteri.c

BNS_SRCS				= ft_lstsize.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c

OBJS					= $(SRCS:%.c=%.o)

BNS_OBJS				= $(BNS_SRCS:%.c=%.o)

OBJS		= $(SRCS:.c=.o)
BNS_OBJS	= $(SRCS_bonus:.c=.o)

CC 			= gcc
CFLAGS		= -g3 -Wall -Wextra -Werror
dbCFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address

RM			= rm -rf

NAME		= libft.a

$(NAME)		: $(OBJS)
				ar rs $(NAME) $(OBJS)

all			: bonus

bonus		: $(NAME) $(BNS_OBJS)
				ar rs $(NAME) $(BNS_OBJS)

clean		:
				$(RM) $(OBJS) $(BNS_OBJS)

<<<<<<< HEAD
bonus	:	$(NAME)
		gcc $(FLAGS) -c $(BNS_SRCS) -I./
		ar rc $(NAME) $(BNS_OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:
		make fclean
		make all
=======
fclean		: clean
				$(RM) *.out* $(NAME) *.gch

re			: fclean $(NAME)
>>>>>>> 507261cb3cceb07365f8339c8bbdfd9fa7936b32

.PHONY		: run all clean fclean re