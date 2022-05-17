/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:53:40 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:53:41 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**split_body(s, c, result, size)
{
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	**result;
	size_t	size;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	split_body(s, c, result, size);
	return (result);
}

