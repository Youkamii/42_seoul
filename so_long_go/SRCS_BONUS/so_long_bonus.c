/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:24 by jashin            #+#    #+#             */
/*   Updated: 2022/10/01 16:20:54 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	argv_checker(char *argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\n유효하지 않은 입력입니다\n");
		exit(1);
	}
	game.map = read_map(argv[1]);
	if (map_checker(&game) && argv_checker(argv[1]))
	{
		game_init(&game);
		gameplay(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		if (game.map)
			free_map(game.map);
		printf("Error\n유효하지 않은 맵입니다\n");
		exit(1);
	}
	return (0);
}
