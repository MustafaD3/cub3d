/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 01:30:22 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/14 01:41:44 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void free_game(t_game *game)
{
	int	i;

	if(game->map->matrix)
	{
		i = 0;
		while(game->map->matrix[i])
		{
			free(game->map->matrix[i]);
			i++;
		}
		free(game->map->matrix);
		game->map->matrix = NULL;
	}
	free(game->map->c);
	free(game->map->no);
	free(game->map->so);
	free(game->map->ea);
	free(game->map->we);
	free(game->map->f);
	mlx_destroy_image(game->mlx, game->window_data.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}
