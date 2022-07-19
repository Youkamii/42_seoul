#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar_fd(va_arg(ap, int)));
	if (format == 's')
		return (ft_putstr_fd(va_arg(ap, char *)));
	if (format == 'p')
		return (ft_putptr_fd(va_arg(ap, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(ap, int)));
	if (format == 'u')
		return (ft_putnbr_fd_u(va_arg(ap, unsigned int), "0123456789", 10));
	if (format == 'x')
		return (ft_putnbr_fd_u(va_arg(ap, unsigned int), \
		"0123456789abcdef", 16));
	if (format == 'X')
		return (ft_putnbr_fd_u(va_arg(ap, unsigned int), \
		"0123456789ABCDEF", 16));
	if (format == '%')
		return (ft_putchar_fd('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_format(ap, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	main(void)
{
	ft_printf("%c", "123");
	return (0);
}

