NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= push_swap.c		\ 
			utils_rr.c			\
			utils_rrr.c			\
			utils_sspa.c		\
			arrayset.c			\
			sort.c				\
			utils_arrayset.c	\
			sort_utils.c		\
			sort_rotate_utils.c	\
			sort_rotate.c		\

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re
