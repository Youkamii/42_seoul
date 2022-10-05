/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyeok <chyeok@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 00:44:24 by chyeok            #+#    #+#             */
/*   Updated: 2022/10/06 00:44:24 by chyeok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_opengl/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		move_count;
	int		endgame;
}	t_game;

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC 53
# define KEY_Q 12

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_UP	126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);
void	nothing_happen(char key, t_game *game);

#endif
