/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:57:34 by jashin            #+#    #+#             */
/*   Updated: 2022/10/01 16:20:43 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animation(t_game *game)
{
	if (game->loop < 1000)
	{
		game->loop++;
		return (0);
	}
	game->loop = 0;
	mlx_destroy_image(game->mlx, game->img_enemie);
	if (game->enemie_animation == 1)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN1.xpm", &game->img_w, &game->img_h);
	else if (game->enemie_animation == 2)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN2.xpm", &game->img_w, &game->img_h);
	else if (game->enemie_animation == 3)
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN3.xpm", &game->img_w, &game->img_h);
	else if (game->enemie_animation == 4)
	{
		game->img_enemie = mlx_xpm_file_to_image
			(game->mlx, "assets/images/EN4.xpm", &game->img_w, &game->img_h);
		game->enemie_animation = 0;
	}
	map_draw(game);
	game->enemie_animation++;
	return (0);
}
