/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:45:19 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/06 00:45:19 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->move_count);
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, keypress, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, exit_game, game);
	mlx_loop(game->mlx);
}
