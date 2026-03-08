/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkili@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 21:36:42 by mdalkili          #+#    #+#             */
/*   Updated: 2026/02/23 23:42:31 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	extension_error(int type)
{
	if (type == LENGTH)
		printf("The file must be 4 characters or longer.\n");
	if (type == HIDDEN)
		printf("The map file should not be private.\n");
	if (type == EXTENSION_NAME)
		printf("The map file must have a .cub extension.\n");
}

int	append_row_two(t_map *map)
{
	int		i;
	char	**new_matrix;

	new_matrix = (char **)malloc(sizeof(char *)
			* (map->matrix_current_row + 1));
	if (!new_matrix)
	{
		perror("malloc:");
		return (0);
	}
	i = 0;
	while (map->matrix[i])
	{
		new_matrix[i] = map->matrix[i];
		i++;
	}
	new_matrix[i++] = map->read_vars.buffer;
	new_matrix[i] = NULL;
	map->matrix_current_row++;
	free(map->matrix);
	map->matrix = new_matrix;
	return (1);
}

static int	flood_fill(char **map, int i, int j, int h)
{
	if (i < 0 || j < 0)
		return (0);
	if (i >= h || j >= (int)ft_strlen(map[i]))
		return (0);
	if (map[i][j] == ' ' || map[i][j] == '\0')
		return (0);
	if (map[i][j] == '1' || map[i][j] == 'F')
		return (1);
	map[i][j] = 'F';
	if (!flood_fill(map, i + 1, j, h))
		return (0);
	if (!flood_fill(map, i - 1, j, h))
		return (0);
	if (!flood_fill(map, i, j + 1, h))
		return (0);
	if (!flood_fill(map, i, j - 1, h))
		return (0);
	return (1);
}

static int	player_control(t_map *map, int i)
{
	int		state;
	char	c;

	state = 0;
	while (map->matrix[map->matrix_current_row])
	{
		i = 0;
		while (map->matrix[map->matrix_current_row][i])
		{
			c = map->matrix[map->matrix_current_row][i];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				map->matrix[map->matrix_current_row][i] = '0';
				if (!state)
					state = 1;
				else
					return (error_print("Multiple player error\n"));
			}
			i++;
		}
		map->matrix_current_row++;
	}
	if (!state)
		return (error_print("Player not found\n"));
	return (1);
}

int	map_control(t_game *game)
{
	char	**copy_map;
	int		result;

	game->map->matrix_current_row = 0;
	if (game->map->row_count < 3)
		return (error_print("Map too small\n"));
	if (!player_control(game->map, 0))
		return (0);
	copy_map = deep_copy_map(game->map->matrix);
	result = flood_fill(copy_map, game->player->p_y,
			game->player->p_x, game->map->row_count);
	free_char_map(copy_map);
	if (!result)
		return (error_print("There is an escape route on the map.\n"));
	return (1);
}
