/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:02:38 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/13 13:02:40 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
void	ft_slice(int r);

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_slice(int r)
{
	int	piece;

	if (r > 9)
	{
		piece = r % 10 + '0';
		r = r / 10;
		ft_putnbr(r);
		ft_putchar(piece);
	}
	else if (r < 0)
	{
		write (1, "-", 1);
		r = r * -1;
		ft_putnbr(r);
	}
	else
	{
		ft_putchar(r % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	int	i;

	i = nb;
	if (i == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else
	{
		ft_slice(i);
	}
}
