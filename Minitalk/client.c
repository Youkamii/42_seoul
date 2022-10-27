/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:07:53 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/27 19:09:26 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int pid, char *str, int strlen)
{
	int	byte;
	int	bit;
	int	tmp;

	byte = 0;
	while (byte < strlen)
	{
		bit = 0;
		while (bit < 8)
		{
			tmp = str[byte] >> (7 - bit) & 1;
			if (tmp == 0)
				kill(pid, SIGUSR1);
			else if (tmp == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			bit++;
		}
		usleep(1000);
		byte++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;
	int		strlen;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_putstr_fd("Argument Error\n", 1);
		exit(1);
	}
	else if (pid < 100 || pid > 99998)
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
