#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

# include "./libft/libft.h"

void	recv_sig(int sig);

void	ft_signal(int pid, char *str, int strlen);

#endif