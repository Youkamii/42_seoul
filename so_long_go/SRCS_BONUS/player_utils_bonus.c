/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:48 by jashin            #+#    #+#             */
/*   Updated: 2022/10/01 16:05:12 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	dead_draw(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_clear_window(game->mlx, game->win);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "assets/images/T.xpm", &game->img_w, &game->img_h);
	game->endgame = 1;
	map_draw(game);
}

void	nothing_happen(char key, t_game *game)
{
	if (key == 'w')
		game->y_player += 1;
	else if (key == 's')
		game->y_player -= 1;
	else if (key == 'd')
		game->x_player -= 1;
	else if (key == 'a')
		game->x_player += 1;
	mlx_clear_window(game->mlx, game->win);
	map_draw(game);
}
