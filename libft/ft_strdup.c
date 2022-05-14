/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:58:10 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:58:11 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*tmp_str;

	len = ft_strlen(str);
	i = 0;
	*tmp_str = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp_str)
		return (0);
	while (i < len)
	{
		tmp_str[i] = str[i];
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}
