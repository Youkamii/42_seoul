/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:10:13 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/27 16:10:15 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_match(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_matching(char *src, char *charset, int i)
{
	if (src[i - 1] && src[i + 1]
		&& !ft_match(src[i + 1], charset) && ft_match(src[i], charset))
		return (1);
	return (0);
}

int	ft_how_many(char *src, char *charset)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_match(src[i], charset))
		i++;
	if (!src[i])
		return (0);
	while (src[i])
	{
		if (ft_matching(src, charset, i))
			res++;
		i++;
	}
	res++;
	return (res);
}

int	ft_each_len(char *str, char *charset, int j)
{
	int	i;

	i = 0;
	while (!ft_matching(str, charset, i + j) && str[i + j])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	res = malloc(sizeof(char *) * (ft_how_many(str, charset) + 1));
	i = 0;
	j = 0;
	while (i < ft_how_many(str, charset))
	{
		k = 0;
		while (ft_match(str[j], charset))
			j++;
		res[i] = malloc(sizeof(char) * (ft_each_len(str, charset, j) + 1));
		while (!ft_matching(str, charset, j) && str[j])
		{
			if (!ft_match(str[j], charset))
				res[i][k++] = str[j];
			j++;
		}
		j += 1;
		res[i++][k] = '\0';
	}
	res[i] = 0;
	return (res);
}
