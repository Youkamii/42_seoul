/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:51:30 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 15:51:45 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s1)
		return (0);
	else if (!set)
		return (my_strdup(s1));
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]))
	{
		if (len - 1 < 1)
			break;
		len--;
	}
	if (i > len)
		return (0);
	res = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1[i], len - i + 1);
	return (res);
}
