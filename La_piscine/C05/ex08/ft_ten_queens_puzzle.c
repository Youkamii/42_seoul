/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:19:32 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/24 20:19:33 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_answer[10];
int		g_column[10];
int		g_l_cross[23];
int		g_r_cross[23];
int		g_count;

void	ft_putstr(void)
{
	write(1, g_answer, 10);
	write(1, "\n", 1);
	g_count++;
	return ;
}

void	ft_dfs(int x)
{
	int	i;

	i = 0;
	if (x == 10)
		ft_putstr();
	while (i <= 9)
	{
		if (!g_column[i] && !g_l_cross[i + x] && !g_r_cross[x - i + 10])
		{
			g_column[i] = 1;
			g_l_cross[i + x] = 1;
			g_r_cross[x - i + 10] = 1;
			g_answer[x] = i + '0';
			ft_dfs(x + 1);
			g_column[i] = 0;
			g_l_cross[i + x] = 0;
			g_r_cross[x - i + 10] = 0;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	ft_dfs(0);
	return (g_count);
}
