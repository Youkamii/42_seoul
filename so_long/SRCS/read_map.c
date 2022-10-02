/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:03:03 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/02 20:03:04 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *path)
{
	int 	fd;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	holder_map = ft_strdup("");
	return (map);

}
