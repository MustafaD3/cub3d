#include "cub3d.h"

static void init_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->f = NULL;
	map->c = NULL;
	map->matrix = NULL;
	map->matrix_current_row = 0;
}

static void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	init_map(map);
	game->cell_size = 64;
	game->player_size = 32;
}

int main(int argc,char **argv)
{
	t_game	game;
	t_map	map;

	if(argc != 2)
		return (1);
	if(!extension_control(argv[1]))
		return (1);
	init_game(&game,&map);
	read_and_parse_map(argv[1], &map);
	start_game(&game);
	free_game(&game);
	return (0);
}