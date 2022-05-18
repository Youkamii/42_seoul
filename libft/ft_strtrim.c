/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:51:30 by chyeok            #+#    #+#             */
/*   Updated: 2022/05/14 15:51:45 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!(s1 && set))
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len && s1[len - 1] && ft_strchr(set, s1[len - 1]))
		len--;
	res = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!res)
		return (NULL);
	return (res);
}

	// size_t	start;
	// size_t	end;
	// char	*result;

	// start = 0;
	// if (s1 == NULL || set == NULL) //상황에 따라서 이런식의 오류처리는 안해도됩니다
	// 	return (0);
	// end = ft_strlen(s1); //end값을 문자열 끝(=문자열길이)으로 잡습니다.
	// while (s1[start] && ft_strchr(set, s1[start])) //set문자가 아닐때까지 start값을 증가
	// 	start++;
	// while (end && s1[end - 1] && ft_strchr(set, s1[end - 1])) //set문자가 아닐때까지 end값을 감소
	// 	end--;
	// if (start > end)  // start > end라는 것은 유효한 문자열이 없다는 뜻입니다
	// 	return (ft_strdup("")); // '\0'문자한개만 가진 메모리로 반환
	// result = ft_substr(s1, start, end - start); //위에서구한 start, end값으로 원하는 문자열복사
	// return (result);
