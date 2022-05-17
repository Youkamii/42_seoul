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

int	cipher(long int nbr)
{
	int	cip;

	cip = 0;
	if (nbr <= 0)
		cip++;
	while (nbr)
	{
		nbr /= 10;
		cip++;
	}
	return (cip);
}

void	iitoa(char *str, long int nbr, int size)
{
	if (nbr == 0)
	{
		str[0] = '0';
	}
	if (nbr / 10 != 0)
		iitoa(str, nbr / 10, size - 1);
	else
	{
		*(str + size) = nbr + '0';
		return ;
	}
	iitoa (str, nbr % 10, size);
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
	iitoa(str, tmp_nbr, size - 1);
	str[size] = '\0';
	return (str);
}
