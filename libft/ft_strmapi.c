/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:03:24 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 15:03:26 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t i;
	char* res;

	i = 0;
	if (!(str || f))
		return (0);
	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[i])
	{
		res[i] = f(i, str[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
