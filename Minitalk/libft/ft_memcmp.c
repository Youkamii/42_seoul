/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:47:40 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 04:13:12 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *dest, const void *src, size_t size)
{
	const unsigned char	*i;
	const unsigned char	*j;

	i = (unsigned char *)dest;
	j = (unsigned char *)src;
	while (size-- > 0)
	{
		if (*i != *j)
			return (*i - *j);
		i++;
		j++;
	}
	return (0);
}
