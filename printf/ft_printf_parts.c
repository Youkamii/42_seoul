/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 07:39:26 by chyeok            #+#    #+#             */
/*   Updated: 2022/07/20 07:39:41 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}


int	ft_putnbr(int n)
{
	long long int	long_num;
	char			c;
	int				i;

	long_num = n;
	if (long_num < 0)
	{
		write(1, "-", 1);
		long_num *= -1;
		i++;
	}
	if (long_num >= 10)
	{
		ft_putnbr(long_num / 10);
		i++;
	}
	c = '0' + (long_num % 10);
	write(1, &c, 1);
	return (i);
}
