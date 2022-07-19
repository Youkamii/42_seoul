#include "ft_printf.h"

int ft_putnbr_fd(int n)
{
	int	nbr;
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648"));
	else if (n < 0)
	{
		write(1, "-", 1);
		i += ft_putnbr_fd(-n) + 1;
	}
	else
	{
		nbr = n % 10;
		n /= 10;
		if (n >= 1)
			i += ft_putnbr_fd(n);
		i += ft_putchar_fd("0123456789"[nbr]);
	}
	return (i);
}

int	ft_putstr_fd(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}

int	ft_putptr_fd(void *ptr)
{
	int	i;

	i = 0;
	i += ft_putstr_fd("0x");
	i += ft_putnbr_fd_p((unsigned long int)ptr);
	return (i);
}

int	ft_putnbr_fd_p(unsigned long int n)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = n % 16;
	n /= 16;
	if (n >= 1)
		i += ft_putnbr_fd_p(n);
	i += ft_putchar_fd("0123456789abcdef"[nbr]);
	return (i);
}

int	ft_putnbr_fd_u(unsigned int n, char *base, int base_n)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = n % base_n;
	n /= base_n;
	if (n >= 1)
		i += ft_putnbr_fd_u(n, base, base_n);
	i += ft_putchar_fd(base[nbr]);
	return (i);
}
