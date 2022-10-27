#include "minitalk.h"

void	recv_sig(int sig)
{
	static char	tmp;
	static int	bit;

	if (bit < 7)
	{
		if (sig == SIGUSR1)
		{
			tmp |= 0;
			tmp <<= 1;
		}
		else if (sig == SIGUSR2)
		{
			tmp |= 1;
			tmp <<= 1;
		}
	}
	else if (bit == 8)
		write(1, &tmp, 1);
	bit = 0;
	tmp = 0;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" : getpid\n", 1);
	signal(SIGUSR1, recv_sig);
	signal(SIGUSR2, recv_sig);
	while (1)
		pause();
}