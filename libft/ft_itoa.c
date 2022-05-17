/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:45:04 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:45:05 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cipher(int nbr)
{
	int	tmp_nbr;
	int	cip;

	tmp_nbr = nbr;
	cip = 1;
	if (tmp_nbr < 0)
	{
		nbr *= -1;
		cip++;
	}
	while (tmp_nbr >= 10)
	{
		tmp_nbr /= 10;
		cip++;
	}
	return (cip);
}

void	itoa(char *str, int nbr, int size)
{
	if (nbr / 10 != 0)
		itoa(str, nbr / 10, size - 1);
	else
	{
		*(str + size) = nbr + '0';
		return ;
	}
	itoa (str, nbr % 10, size);
}

char	*ft_itoa(int nbr)
{
	int		size;
	char	*str;
	int		tmp_nbr;

	size = cipher(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	tmp_nbr = nbr;
	if (tmp_nbr < 0)
	{
		str[0] = '-';
		tmp_nbr *= -1;
	}
	make_str(str, tmp_nbr, size - 1);
	str[size] = '\0';
	return (str);
}
