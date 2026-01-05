/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:56:39 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/26 03:02:20 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void collision_control(t_game *game, int collision_direction[4])
{
	collision_direction[0] = 0;
	collision_direction[1] = 0;
	collision_direction[2] = 0;
	collision_direction[3] = 0;
	if(game->map->matrix[(int)game->player->p_y][(int)game->player->p_x - 1] == '1')
		collision_direction[0] = 1;
	if(game->map->matrix[(int)game->player->p_y][(int)game->player->p_x + 1] == '1')
		collision_direction[1] = 1;
	if(game->map->matrix[(int)game->player->p_y - 1][(int)game->player->p_x] == '1')
		collision_direction[2] = 1;
	if(game->map->matrix[(int)game->player->p_y + 1] && game->map->matrix[(int)game->player->p_y + 1][(int)game->player->p_x] == '1')
		collision_direction[3] = 1;
}

int move(int keycode, void *v_game)
{
	t_game *game;
	int		collision_direction[4];
	game = (t_game *)v_game;
	
	collision_control(game, collision_direction);

	if(keycode == LEFT_ARROW && !collision_direction[0] &&game->player->p_x > 0)
		game->player->angle -= 0.1;
	if(keycode == RIGHT_ARROW && !collision_direction[1] && game->player->p_x < game->width / game->cell_size - 1)
		game->player->angle += 0.1;
	if(keycode == UP_ARROW && !collision_direction[2] &&game->player->p_y > 0)
		game->player->p_y -= 1;
	if(keycode == DOWN_ARROW && !collision_direction[3] &&game->player->p_y < game->height / game->cell_size - 1)
		game->player->p_y += 1;
	return (1);
}

int	close_window(void *param)
{
	t_game *game;

	game = (t_game *)param;
	mlx_loop_end(game->mlx);
	return 0;
}