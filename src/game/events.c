/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:53:15 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/22 00:19:15 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void start_events(t_game *game)
{
	mlx_hook(game->mlx_win, ON_DESTROY,0 ,close_window, (void *)game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, KEYPRESS_MASK, move, (void *)game);
}