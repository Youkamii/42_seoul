/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:05:53 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/23 17:05:54 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *c)
{
	write(1, c, 1);
}

int	main(int argc, char **argv)
{
	int	le;
	int	ri;

	le = argc - 1;
	ri = 0;
	while (le >= 1)
	{
		while (argv[le][ri])
		{
			ft_putchar(&argv[le][ri]);
			ri++;
		}
		ri = 0;
		write (1, "\n", 1);
		le--;
	}
	return (0);
}
