/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:41:30 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/20 07:41:32 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_type(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (format == 'x')
		return (ft_putnbr(va_arg(ap, unsigned int), \
		"0123456789abcdef", 16));
	else if (format == 'X')
		return (ft_putnbr(va_arg(ap, unsigned int), \
		"0123456789ABCDEF", 16));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	cur;
	int		res;

	res = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	else
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				res += ft_format_type(ap, format[i + 1]);
				cur++;
			}
			else
				res += ft_putchar(format[i]);
			cur++;
		}
	}
	va_end(ap);
	return (res);
}
