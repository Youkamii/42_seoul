/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:49:23 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/24 12:49:25 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (j <= power)
	{
		i *= nb;
		j++;
	}
	return (i);
}
