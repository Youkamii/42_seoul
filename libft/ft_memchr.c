/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:45:29 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:45:30 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned int	i;

	i = n;
	tmp_s = (unsigned char *)s;
	while (i)
	{
		if (*tmp_s == c)
			return (tmp_s);
		tmp_s++;
		i--;
	}
	return ((void *)0);
}
