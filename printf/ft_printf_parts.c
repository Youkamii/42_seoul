/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:39:26 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/20 15:41:24 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putnbr(int n)
{
	int	nbr;
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		write(1, "-", 1);
		i += ft_putnbr(-n) + 1;
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

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr_ptr((unsigned long int)ptr);
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

int	ft_putnbr_base(unsigned int n, char *base, int base_n)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = n % base_n;
	n /= base_n;
	if (n >= 1)
		i += ft_putnbr_base(n, base, base_n);
	i += ft_putchar(base[nbr]);
	return (i);
}
