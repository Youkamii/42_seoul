/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:39:26 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/20 10:08:25 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = ft_strlen(s);
	write(1, s, 1);
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr_ptr((unsigned long int)ptr);
	return (i);
}

int	ft_putnbr(int n)
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
			i += ft_putnbr(n);
		i += ft_putchar("0123456789"[nbr]);
	}
	return (i);
}

int	ft_putnbr_ptr(unsigned long int n)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = n % 16;
	n /= 16;
	if (n >= 1)
		i += ft_putnbr_ptr(n);
	i += ft_putchar("0123456789abcdef"[nbr]);
	return (i);
}

int	ft_putnbr_u(unsigned int n, char *base, int base_n)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = n % base_n;
	n /= base_n;
	if (n >= 1)
		i += ft_putnbr_u(n, base, base_n);
	i += ft_putchar(base[nbr]);
	return (i);
}
