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

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	size_t	len_s;

	tmp_s = (char *)s;
	len_s = ft_strlen(s);
	while (len_s > 0)
	{
		if (tmp_s[len_s] == (char)c)
			return (tmp_s + len_s);
		len_s--;
	}
	if (tmp_s[len_s] == (char)c)
		return (tmp_s);
	return (0);
}
