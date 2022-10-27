CC		= gcc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f

INCLUDES	= ./minitalk.h

LIBFT_DIR	= ./libft
LIBFT		= ./libft/libft.a

CLIENT	= clinet
SERVER	= server

SRCS_C	= client.c
SRCS_S	= server.c
OBJS_C	= $(SRCS_C:.c=.o)
OBJS_S	= $(SRCS_S:.c=.o)

all : $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(CLIENT) : $(OBJS_C)
	$(CC) $(CFLAG) $< -o $@ $(LIBFT)

$(SERVER) : $(OBJS_S)
	$(CC) $(CFLAG) $< -o $@ $(LIBFT)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
	
clean :
	$(RM) $(OBJS_C) $(OBJS_S)

fclean : clean
	$(RM) $(CLIENT) $(SERVER) 
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY : all clean fclean re