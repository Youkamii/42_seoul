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

static int	str_counter(char *str, char c)
{
	int	i;
	int	indicator;
	int	nstr;

	i = 0;
	nstr = 0;
	while (str[i])
	{
		indicator = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i])
			i++;
		if (indicator == 1)
			nstr++;
	}
	return (nstr);
}

static int	str_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ptr_free(char **ptr, int i)
{
	while (i > 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nstr;
	int		i;

	if (!s)
		return (NULL);
	nstr = str_counter((char *)s, c);
	ptr = (char **)malloc((nstr + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (nstr > 0)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_substr(s, 0, str_len(s, c));
		if (!ptr[i])
			return (ptr_free(ptr, i));
		s = s + str_len(s, c);
		i++;
		nstr--;
	}
	ptr[i] = 0;
	return (ptr);
}
