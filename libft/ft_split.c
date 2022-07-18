/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:53:40 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 07:13:44 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	ft_split_elem(char **ptr, char const *s, char c)
{
	int		i;
	char	*elem;

	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			elem = ft_calloc(i + 1, sizeof(char));
			*ptr++ = elem;
			if (elem == NULL)
				return (0);
			while (*s && *s != c)
				*elem++ = *s++;
			*elem = '\0';
		}
	}
	*ptr = NULL;
	return (1);
}

static char	**ft_free(char **ptr)
{
	char	**str;

	if (ptr)
	{
		str = ptr;
		while (*str)
		{
			free(*str);
			*str++ = NULL;
		}
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		cnt;
	int		on_elem;
	int		i;

	if (!s)
		return (NULL);
	cnt = 0;
	on_elem = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			on_elem = 0;
		else if (!on_elem)
		{
			cnt++;
			on_elem = 1;
		}
		i++;
	}
	result = ft_calloc(cnt + 1, sizeof(char *));
	if (result == NULL || !ft_split_elem(result, s, c))
		return (ft_free(result));
	return (result);
}
