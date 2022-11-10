# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 14:36:27 by chyeok            #+#    #+#              #
#    Updated: 2022/11/10 20:34:06 by chyeok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isdigit.c ft_strlcpy.c ft_calloc.c ft_split.c \
		ft_isspace.c ft_strlen.c ft_bzero.c ft_memset.c

OBJS = $(SRCS:.c=.o)
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -f

all: $(NAME)

clean:
	$(RM) $(RMFLAGS) -f $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: all clean fclean re
