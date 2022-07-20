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

int ft_putnbr

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_putnbr((unsigned long int)ptr);
	return (i);
}