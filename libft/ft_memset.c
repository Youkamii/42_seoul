/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:17:17 by chyeok            #+#    #+#             */
/*   Updated: 2022/03/15 19:08:36 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_dest;

	i = 0;
	tmp_dest = (unsigned char *)dest;
	while (i < len)
	{
		tmp_dest[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
