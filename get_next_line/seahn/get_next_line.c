/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seahn <seahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:13:59 by seahn             #+#    #+#             */
/*   Updated: 2022/07/01 21:09:45 by seahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		count;
	char	*temp;

	count = 1; // flag
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE); // read의 반환값이 뭘까? 1. read 정상 성공 -> read한 문자열의 길이 2. read 실패-> -1 3. 다 읽었을 때 -> 0 
		if (count == -1)
			return (0); // 지금까지 한거 다 모른다 0만 안다
		else if (count == 0)
			break ; // 지금까지 한건 다 알고있다
		buffer[count] = '\0'; // [읽은 문자]"[\0]""
		if (!backup) // 가장 처음 읽었을 때
			backup = ft_strdup(""); // 백업을 만들어 줍니다.
		temp = backup; // temp에 담아주는 이유
		backup = ft_strjoin(temp, buffer); // 조인할 때 원본에다가 조인하면 오류가 나더라 포인터가 엇갈리더라 seg fault가 뜨더라
		if (!backup) // 널가드
			return (NULL);
		free(temp); // 더이상 temp 안쓰니까 (실제 건물을 크레인으로 뿌순다)
		temp = NULL; // 접근 방지 (주소명을 행정적으로 삭제한 것)
		if (ft_strchr(buffer, '\n')) // 버퍼에서 개행을 발견했다. 개행 뒤는 next니까
			break ;
	}
	return (backup);
}
// 1\n2\n3\0

// 1
// 2
// 3

static char	*cut_back(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') // "한 줄"에서 널이나 개행을 만날 때 까지 포인터를 움직입니다.
		i++;
	if (line[i] == '\0') // 널을 만났다? 다 읽은것입니다. 0을 반환합니다
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i); // 개행을 만났으니 개행 뒤를 짜른다. result에다가 삽입한다.
	if (!result)
		return (NULL);
	if (result[0] == '\0') // 개행 뒤가 없으면
	{
		free(result); 
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0'; // 문자열은 널로 끝나야 하니까 널을 붙여준다.
	return (result); // 1. 읽은 부분 문자열 2. 아직 읽지 않은 부분 문자열 . 백업과 관련
}

// 192.168.56.1 : 4242번으로 데이터 교환을 하겠다 8080번으로 교환 -> 주소 : 포트
// 3번 fd로 파일을 열겠다. 4번 fd로 열겠다 컴퓨터 구조가 그런것이다. -> 파일 : 파일 디스크립터
// fd를 알면 우리의 운영체제에서 파일을 읽으면 그 파일에 해당하는 숫자를 부여한다. name tag : 볼펜(1), 연필(2), 
// fd = 2 -> 가방에서 연필을 볼 수 있다
// backup[1] fd 1번의 백업
// backup fd 2번의 백업
// 10240개의 백업을 저장 가능 fd가 들어갑니다.
// a = get_next_line(1) 1번 파일은 1번 파일의 백업
// b = get_next_line(2) 2번 파일은 2번 파일의 백업
// a = get_next_line(1)
// b = get_next_line(2)
// a = get_next_line(1)
// b = get_next_line(2)
// a = get_next_line(1)
// b = get_next_line(2)

char	*get_next_line(int fd) 
{
	char		*line; // next_line : "한 줄"을 읽어서 반환할 줄
	char		*buffer; // 한 줄을 "읽어서" 반환 -> ex: 3이다 그러면 문자열을 3개씩 받아서 넣어주는걸 반복합니다 길이 100인 문자열이 있다 그러면 버퍼를 몇번 넣고 비워야 할까요?
	static char	*backup[OPEN_MAX]; // 우리가 백업을 해두는 문자열 왜 백업을 하는가? 여러 줄 읽으려고 한다

	if (fd < 0 || BUFFER_SIZE <= 0) // 예외 처리. 버퍼 크기가 음수? 논리적 불가능 , fd 음수? fd는 애초에 0부터 시작하도록 설계됨
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // 버퍼를 실제로 할당한다. buffer = [a][\0]
	if (!buffer) // 널가드
		return (NULL);
	line = read_line(fd, buffer, backup[fd]); // 한 줄을 읽어서 line에 저장한다
	free(buffer); // 버퍼를 크레인으로 뿌순다
	buffer = NULL; // 버퍼의 행정적 삭제
	if (!line) // 읽지 않았어 사장님 결재 
	{
		free(backup[fd]); // 백업 삭제
		backup[fd] = NULL; // 백업 행정적 삭제
		return (NULL); // null 반환
	}
	backup[fd] = cut_back(line); // 99.9%
	return (line);
}

int main()
{
	char *line;

	line = get_next_line(0);
	printf("%s", line);
	free(line);
	line = get_next_line(0);
	printf("%s", line);
	system("leaks a.out");
}
