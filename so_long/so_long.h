/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:24:40 by chyeok            #+#    #+#             */
/*   Updated: 2022/09/24 13:24:45 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	char	*ptr;
	int		str;
	int		x;
	int		y;
	int		lines;
	int		columns;
	int		x_pos;
	int		y_pos;
	int		x_ext;
	int		y_ext;
	int		s;
	int		player;
	int		collectible;
	int		ext;
}				t_var;
