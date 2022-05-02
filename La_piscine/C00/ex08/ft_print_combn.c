/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frint_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 09:49:27 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/16 09:49:29 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	g_answer[10];

int	blank(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (g_answer[n - i - 1] != '9' - i)
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int depth, int before, int n)
{
	int	i;

	i = 0;
	if (depth == n)
	{
		while (i < n)
		{
			write(1, &g_answer[i], 1);
			i++;
		}
		if (!blank(n))
			write(1, ", ", 2);
		return ;
	}
	while (i <= 9)
	{
		if (i > before)
		{
			g_answer[depth] = i + '0';
			dfs(depth + 1, i, n);
		}
		i++;
	}
}

void	ft_print_combn(int n)
{
	dfs(0, -1, n);
}
