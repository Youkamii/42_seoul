/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:45:04 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 06:05:33 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	cipher(long int nbr)
{
	size_t	cip;

	cip = 0;
	if (!nbr)
		return (1);
	else if (nbr < 0)
		cip++;
	while (nbr)
	{
		nbr /= 10;
		cip++;
	}
	return (cip);
}

char	*ft_itoa(int nbr)
{
	char		*str;
	size_t		len;
	long long	res;

	len = cipher(nbr);
	res = (long long)nbr;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (res < 0)
	{
		str[0] = '-';
		res *= -1;
	}
	else if (!res)
		str[0] = '0';
	str[len] = 0;
	len -= 1;
	while (res)
	{
		str[len] = res % 10 + '0';
		res /= 10;
		len--;
	}
	return (str);
}
