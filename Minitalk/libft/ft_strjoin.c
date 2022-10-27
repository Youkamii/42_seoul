/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:59:23 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 04:28:19 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_i;
	size_t	s2_j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	s1_i = 0;
	while (s1[s1_i])
	{
		res[s1_i] = s1[s1_i];
		s1_i++;
	}
	s2_j = 0;
	while (s2[s2_j])
	{
		res[s1_i + s2_j] = s2[s2_j];
		s2_j++;
	}
	res[s1_i + s2_j] = '\0';
	return (res);
}
