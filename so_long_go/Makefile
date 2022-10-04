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
				./SRCS/exit.c \


SRCS_BONUS	=	./SRCS_BONUS/so_long_bonus.c \
				./SRCS_BONUS/draw_bonus.c \
				./SRCS_BONUS/init_bonus.c \
				./SRCS_BONUS/read_bonus.c \
				./SRCS_BONUS/valid_check_bonus.c \
				./SRCS_BONUS/player_update_bonus.c \
				./SRCS_BONUS/play_bonus.c \
				./SRCS_BONUS/exit_bonus.c \
				./SRCS_BONUS/display_move_bonus.c \
				./SRCS_BONUS/animation_bonus.c \
				./SRCS_BONUS/player_utils_bonus.c

OBJS			= $(SRCS:%.c=%.o)
OBJS_BONUS		= $(SRCS_BONUS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

ifdef   WITH_BONUS
        OBJECTS    =       $(OBJS_BONUS)
else
        OBJECTS    =       $(OBJS)
endif

all			:	$(NAME)

$(NAME)		:	$(OBJECTS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJECTS) -Llibft -lft -L./mlx_opengl -lmlx -framework OpenGL -framework AppKit

bonus	:
	make WITH_BONUS=1 all

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
