/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:28:10 by chyeok            #+#    #+#             */
/*   Updated: 2022/04/12 16:28:11 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (dest[i] && i < size)
        i++;
    if (i < size)
    {
        while (src[j] && i + j < size - 1)
        {
            dest[i + j] = src[j];
            j++;
        }
        dest[i + j] = '\0';
    }
    return (ft_strlen(dest));
}
