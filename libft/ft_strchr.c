/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:56:06 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 14:56:07 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	if (!(*str))
		return (0);
	else if (c == '\0')
		return ((char *)str);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}
	return (0);
}
