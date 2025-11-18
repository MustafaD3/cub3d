#include "../../cub3d.h"

void	my_mlx_pixel_put(t_window_data *data, int x, int y, int color)
{
	char	*dst;
	int x_sum;
	int y_sum;

	x_sum = x;
	y_sum = y;
	while(x_sum < 500)
	{
	dst = data->addr + (y_sum * data->line_length + x_sum * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		x_sum++;
	}
	x_sum = x;
	while(y_sum < 500)
	{
	dst = data->addr + (y_sum * data->line_length + x_sum * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		y_sum++;
	}
	
}

void start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1920, 1080, "Hello world!");
	game->window_data.img = mlx_new_image(game->mlx, 1920, 1080);
	game->window_data.addr = mlx_get_data_addr(game->window_data.img, &game->window_data.bits_per_pixel, &game->window_data.line_length,
								&game->window_data.endian);
	//my_mlx_pixel_put(&game->window_data, 5, 5, 0x10FFFF12);
	start_events(game);
	draw_map_2d(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->window_data.img, 0, 0);
	mlx_loop(game->mlx);
}