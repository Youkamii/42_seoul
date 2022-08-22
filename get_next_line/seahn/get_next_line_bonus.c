/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seahn <seahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:15:39 by seahn             #+#    #+#             */
/*   Updated: 2022/07/01 18:20:37 by seahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buffer, char *backup)
{
	int		count;
	char	*temp;

	count = 1;
	while (count)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buffer[count] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		if (!backup)
			return (NULL);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backup);
}

static char	*cut_back(char *line)
{
	int		i;
	char	*result;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	result = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!result)
		return (NULL);
	if (result[0] == '\0')
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, backup[fd]);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(backup[fd]);
		backup[fd] = NULL;
		return (NULL);
	}
	backup[fd] = cut_back(line);
	return (line);
}
