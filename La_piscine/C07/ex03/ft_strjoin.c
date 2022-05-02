/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:27:14 by chyeok            #+#    #+#             */
/*   Updated: 2022/01/26 15:27:15 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		j;
	int		k;
	int		count;

	i = 0;
	j = 0;
	j = 0;
	count = 1;
	while (j < size)
		count += ft_strlen(strs[j++]) + ft_strlen(sep);
	tab = malloc(sizeof(char *) * count);
	j = -1;
	while (++j < size)
	{
		while (strs[j][k])
			tab[i++] = strs[j][k++];
		k = 0;
		while (sep[k] && j < size - 1)
			tab[i++] = sep[k++];
		k = 0;
	}
	tab[i] = '\0';
	return (tab);
}
