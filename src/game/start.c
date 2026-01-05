#include "../../cub3d.h"

int game_loop(void *v_game)
{
	t_game  *game;

	game = (t_game *)v_game;
	mlx_clear_window(game->mlx, game->mlx_win);
	memset(game->window_data.addr, 0,
		game->window_data.line_length * 1080);
	draw_map_2d(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->window_data.img, 0, 0);
	return (1);
}

void start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->width, game->height, "Hello world!");
	game->window_data.img = mlx_new_image(game->mlx,
			game->width, game->height);
	game->window_data.addr = mlx_get_data_addr(game->window_data.img,
			&game->window_data.bits_per_pixel,
			&game->window_data.line_length,
			&game->window_data.endian);
	start_events(game);
	mlx_loop_hook(game->mlx, game_loop, (void *)game);
	mlx_loop(game->mlx);
}
