/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:52:38 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:52:39 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	long long int	long_num;
	char			c;

	long_num = n;
	if (long_num < 0)
	{
		write(fd, "-", 1);
		long_num *= -1;
	}
	if (long_num >= 10)
		ft_putnbr_fd(long_num / 10, fd);
	c = '0' + (long_num % 10);
	write(fd, &c, 1);
}
