/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:45:29 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 04:12:34 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s;

	tmp_s = (unsigned char *)s;
	while (n)
	{
		if (*tmp_s != ((unsigned char)c))
			tmp_s++;
		else
			return ((void *)tmp_s);
		n--;
	}
	return (0);
}
