# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/02 20:37:04 by chyeok            #+#    #+#              #
#    Updated: 2022/10/02 20:37:08 by chyeok           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS			=	./SRCS/so_long.c \
				./SRCS/main.c \
				./SRCS/read_map.c
				./SRCS/draw.c \
				./SRCS/init.c \
				./SRCS/read.c \
				./SRCS/valid_check.c \
				./SRCS/player_update.c \
				./SRCS/play.c \
				./SRCS/exit.c \

OBJS			= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJECTS) -Llibft -lft -L./mlx_opengl -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		rm -f $(OBJS_BONUS)
		cd ./libft && make fclean

fclean		:	clean
		rm -f $(NAME)
		@rm -f so_long.dSYM

re			:	fclean all

.PHONY		:	all clean fclean re bonus

