/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:53:15 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/14 01:01:20 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void start_events(t_game *game)
{
	mlx_hook(game->mlx_win, ON_DESTROY,0 ,close_window, (void *)game);
}