/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:07:53 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/29 12:35:55 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int pid, char *str, int strlen)
{
	int	count;
	int	bit;
	int	sign;

	count = 0;
	while (count < strlen)
	{
		bit = 0;
		while (bit < 8)
		{
			sign = str[count] >> (7 - bit) & 1;
			if (sign == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			bit++;
		}
		usleep(300);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	int		strlen;

	if (argc != 3)
	{
		ft_putstr_fd("Argument Error\n", 1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_putstr_fd("Pid Error\n", 1);
		exit(1);
	}
	str = ft_strjoin(argv[2], "\n");
	strlen = ft_strlen(str);
	ft_signal(pid, str, strlen);
	free(str);
	return (0);
}
