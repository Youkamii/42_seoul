/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:58:59 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/26 10:59:00 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*idx;
	int	i;

	if (min >= max)
		return (0);
	idx = malloc(sizeof(int) * ((long long)(max - min)));
	if (!idx)
		return (NULL);
	i = 0;
	while (min < max)
	{
		idx[i] = min;
		min++;
		i++;
	}
	return (idx);
}
