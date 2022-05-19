/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:56:06 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:56:07 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*tmp_str;

	tmp_str = (char *)str;
	while (*tmp_str)
	{
		if (*tmp_str == (char)c)
			return (tmp_str);
		tmp_str++;
	}
	if (c == 0)
		return (tmp_str);
	return (0);
}
