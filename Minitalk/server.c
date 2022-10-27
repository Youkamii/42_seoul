/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:08:02 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/27 19:11:03 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recv_sign(int sign)
{
	static int	tmp = 0;
	static int	bit = 0;

	if (sign == SIGUSR1)
	{
		tmp <<= 1;
		tmp += 1;
		bit++;
	}
	else if (sign == SIGUSR2)
	{
		tmp <<= 1;
		bit++;
	}
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" : getpid\n", 1);
	signal(SIGUSR1, recv_sign);
	signal(SIGUSR2, recv_sign);
	while (1)
		pause();
}
