/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:13:35 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/19 02:26:09 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void draw_square(t_window_data *w, int py, int px, int cell_size, int s, int color)
{
    char *row;
    char *dst;
    unsigned char *p;
    int i;
    int j;
    int bpp;
    int by;
    int bx;

    if (!w || !w->addr)
        return ;
    bpp = w->bits_per_pixel / 8;
    /* compute pixel origin so `s` is centered inside the cell */
    by = py * cell_size + (cell_size - s) / 2;
    bx = px * cell_size + (cell_size - s) / 2;
    i = 0;
    while (i < s)
    {
        row = w->addr + (by + i) * w->line_length;
        j = 0;
        while (j < s)
        {
            dst = row + (bx + j) * bpp;
            if (bpp == 4)
                *(unsigned int *)dst = (unsigned int)color;
            else
            {
                p = (unsigned char *)dst;
                p[0] = (unsigned char)(color & 0xFF);
                if (bpp > 1) p[1] = (unsigned char)((color >> 8) & 0xFF);
                if (bpp > 2) p[2] = (unsigned char)((color >> 16) & 0xFF);
            }
            j++;
        }
        i++;
    }
}

void	draw_map_2d(t_game *game)
{
	 int i;
    int j;

    if (!game || !game->map || !game->map->matrix)
        return ;
    i = 0;
    while (game->map->matrix[i])
    {
        j = 0;
        while (game->map->matrix[i][j])
        {
            if (game->map->matrix[i][j] == '1')
                draw_square(&game->window_data, i, j, game->cell_size, game->cell_size, 0xFFDDBB);
            if (game->map->matrix[i][j] == 'P')
                draw_square(&game->window_data, i, j, game->cell_size, game->player_size, 0x00DDBB);
            j++;
        }
        i++;
    }
}
