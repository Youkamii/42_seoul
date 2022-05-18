/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:47:32 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 15:47:33 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!(*str))
		return (0);
	else
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)str[i]);
		--i;
	}
	return (0);
}
