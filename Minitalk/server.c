#include "minitalk.h"

void	recv_sig(int sign)
{
	static char	tmp;
	static int	bit;

	bit = 0;
	if (sign == SIGUSR1)
	{
		tmp <<= 1;
		tmp += 1;
		bit++;
	}
	else if (sign == SIGUSR2)
	{
		tmp <<= 1;
		bit++;
	}
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
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