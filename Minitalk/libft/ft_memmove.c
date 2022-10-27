/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:39:52 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 06:05:38 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*tmp_dest;
	const char	*tmp_src;
	size_t		i;

	if (dest == src || !size)
		return (dest);
	tmp_src = (char *)src;
	tmp_dest = (char *)dest;
	i = 0;
	if (tmp_dest > tmp_src)
		while (size-- > 0)
			tmp_dest[size] = tmp_src[size];
	else
	{
		while (i < size)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	return (dest);
}
