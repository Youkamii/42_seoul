/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:35:57 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/24 12:35:59 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (nb < 0)
		return (0);
	while (--nb)
	{
		j *= nb;
	}
	return (j);
}
