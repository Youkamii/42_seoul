/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:14:31 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/23 15:14:33 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	write(1, c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argc >= 1 && argv[0][i])
	{
		ft_putchar(&argv[0][i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
