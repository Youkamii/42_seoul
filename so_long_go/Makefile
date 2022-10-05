NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS			=	./SRCS/so_long.c \
				./SRCS/draw.c \
				./SRCS/init.c \
				./SRCS/read.c \
				./SRCS/valid_check.c \
				./SRCS/player_update.c \
				./SRCS/play.c \
				./SRCS/exit.c 

OBJS			= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

OBJECTS    =       $(OBJS)

all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJECTS) -Llibft -lft -L./mlx_opengl -lmlx -framework OpenGL -framework AppKit

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		cd ./libft && make fclean

fclean		:	clean
		rm -f $(NAME)
		@rm -f so_long.dSYM

re			:	fclean all

.PHONY		:	all clean fclean re
