/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:31:15 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/06 00:54:29 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static char	*reading(int fd, char *buffer, char *backup_line)
{
	int		cur;
	char	*tmp;

	cur = 1;
	while (cur)
	{
		cur = read(fd, buffer, BUFFER_SIZE);
		if (cur < 0)
			return (0);
		else if (cur == 0)
			break ;
		buffer[cur] = '\0';
		if (!backup_line)
			backup_line = ft_strdup("");
		tmp = backup_line;
		backup_line = ft_strjoin(tmp, buffer);
		if (!backup_line)
			return (NULL);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup_line);
}

static char	*dvd_line(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	else
	{
		res = ft_substr(line, i + 1, ft_strlen(line) - i);
		if (!res)
			return (NULL);
	}
	if (res[0] == '\0')
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup_line[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = reading(fd, buffer, backup_line[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(backup_line[fd]);
		backup_line[fd] = NULL;
		return (NULL);
	}
	backup_line[fd] = dvd_line(line);
	return (line);
}
