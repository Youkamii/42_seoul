/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liachoi <liachoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:12:14 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/19 12:44:56 by liachoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_spc(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		return ()
	else if (format == 's')
		return
	else if (format == 'p')
		return
	else if (format == 'x')
		return
	else if (format == 'X')
		return
	else if (format == 'd')
		return
	else (format == '%')
		return
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	cur;
	int		res;

	res = 0;
	if (format == NULL)
		return (-1);
	else
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				res += 
			}
			cur++;
		}
	}
	va_start(ap, format);
	va_end(ap);
	return (res);
}
