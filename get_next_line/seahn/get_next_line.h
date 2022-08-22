/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seahn <seahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:15:13 by seahn             #+#    #+#             */
/*   Updated: 2022/07/01 18:18:57 by seahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h> // malloc, free
# include <limits.h> // OPEN_MAX : 상수역 아니고 상수, 함수 아니다. 최대 열릴 수 있는 fd의 수가 정의 되어 있다. 간혹 누군가 그러죠 쓰라고 안한 헤더는 쓰면 안되는거 아닌가요? 응 아니야~ 쓰지 말라는 함수만 안쓰면 돼~
# include <unistd.h> // write, **read**

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1 // BUFFER_SIZE 기본값 = 1
# endif

size_t		ft_strlen(const char *s); // 문자열 길이를 알게 한다
char		*ft_strchr(const char *s, int c); // s에서 c가 있는 메모리 주소를 반환한다
char		*ft_strdup(const char *s1); // 문자열 복사해서 메모리 할당한다
char		*ft_strjoin(char const *s1, char const *s2); // s1s2를 만든다
char		*ft_substr(char const *s, unsigned int start, size_t len); // start부터 len길이 만큼 복붙한다 원본 건들지 않는다
char		*get_next_line(int fd); // 우리의 함수

#endif