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

	count = 1; // 스위치
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE); // 읽어온 버퍼사이즈 크기만큼만 read 해서 buffer에 넣어준다, 오류는 -1, 정상적으로 동작한다면 읽어온 글자 수만큼. count <= BUFFER_SIZE
		if (count == -1)
			return (0); // 오류시 종료하고 0 반환
		else if (count == 0)
			break ; // BUFFER의 크기가 0 == 문자열이 비어있다. 종료
		buffer[count] = '\0'; // 각 버퍼마다 끝에 널문자로 문자열 닫아주기
		if (!backup) // 
			backup = ft_strdup(""); // backup의 초기화
		temp = backup; // backup에 바로 문자열을 붙이게 되면 할당되지 않은 크기의 문자열이 붙기때문에 오류난다.
		backup = ft_strjoin(temp, buffer); // join으로 temp(=backup) + buffer(방금 막 읽어온 문자or문자열(버퍼의 크기만큼) 을 backup에 다시 담아주기)
		if (!backup) // 널가드
			return (NULL);
		free(temp); // temp 사용이 끝났기 때문에 free 1; 내부 데이터 삭제
		temp = NULL; // free 2; 주소 삭제
		if (ft_strchr(buffer, '\n')) // 버퍼를 읽어오다가 개행문자를 만난다면 함수종료
			break ;
	}
	return (backup);
}

static char	*cut_back(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') // line에서 개행이나 널을 만나기 전까지 커서 이동
		i++;
	if (line[i] == '\0') // 널이라면 종료
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i); // line에서 i의 위치부터의 뒤부터 문자열의 끝까지 문자열 전체를 result에 넣어주기
	if (!result) //ㄴㄱㄷ
		return (NULL);
	if (result[0] == '\0') // 가져와서 넣어준게 널이라면 free해주고 종료  (if로 예외처리 가능한가?)
	{
		free(result); 
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0'; //
	return (result); // 반환
}

char	*get_next_line(int fd) // backup[]에 저장될 배열의 번호 : fd
{
	char		*line; // main을 통해 받게되는 읽어올 문자열
	char		*buffer; // 한번에 읽을 수 있는 문자의 개수만큼의 크기가 할당된 문자열을 담을 공간
	static char	*backup[OPEN_MAX]; // fd의 갯수 최대한 많이 받기

	if (fd < 0 || BUFFER_SIZE <= 0) // 버퍼와 fd는 음의 정수가 존재할 수 없음
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // 버퍼 뒤에 널문자로 배열을 닫아줘야하기 때문에 버퍼크기 + 1 (널문자 들어갈 자리)
	if (!buffer) // 널가드
		return (NULL);
	line = read_line(fd, buffer, backup[fd]); // line = backup
	free(buffer); // free 1
	buffer = NULL; //free 2
	if (!line) // ************************************** 25줄
	{
		free(backup[fd]); // f1
		backup[fd] = NULL; // f2
		return (NULL); 
	}
	backup[fd] = cut_back(line); 
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
