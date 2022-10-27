/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:56:06 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/20 04:19:22 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	const char	*tmp_str;

	tmp_str = (char *)str;
	while (*tmp_str)
	{
		if (*tmp_str == (char)c)
			return ((char *)tmp_str);
		tmp_str++;
	}
	if (!c)
		return ((char *)tmp_str);
	return (0);
}
