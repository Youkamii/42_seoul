/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:54:02 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/13 12:54:03 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i, int j, int k, int l);
void	ft_counter(int AAoo, int ooBB);
void	ft_print_comb2(void);

void	ft_putchar(int i, int j, int k, int l)
{
	write (1, &i, 1);
	write (1, &j, 1);
	write (1, " ", 1);
	write (1, &k, 1);
	write (1, &l, 1);
}

void	ft_counter(int AAoo, int ooBB)
{
	int	counter_1;
	int	counter_2;
	int	counter_3;
	int	counter_4;

	counter_1 = AAoo / 10 + '0';
	counter_2 = AAoo % 10 + '0';
	counter_3 = ooBB / 10 + '0';
	counter_4 = ooBB % 10 + '0';
	ft_putchar(counter_1, counter_2, counter_3, counter_4);
	if (!(AAoo == 98 && ooBB == 99))
	{
		write (1, ",", 1);
		write (1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	while (left < 99)
	{
		right = left + 1;
		while (right <= 99)
		{
			if (right > left)
			{
				ft_counter(left, right);
			}
			right++;
		}
		right = right - 100;
		left++;
	}
}
