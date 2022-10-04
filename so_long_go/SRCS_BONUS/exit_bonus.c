/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:57:15 by jashin            #+#    #+#             */
/*   Updated: 2022/10/01 16:20:47 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != (void *)0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_enemie);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
