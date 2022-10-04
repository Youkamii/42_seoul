/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jashin <jashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:57:29 by jashin            #+#    #+#             */
/*   Updated: 2022/10/01 16:20:44 by jashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_move_count(t_game *game)
{
	char	*str;

	str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 25, 20, 0xFFFFFF, "MOVES ");
	mlx_string_put(game->mlx, game->win, 80, 20, 0xFFFFFF, str);
	free(str);
}
