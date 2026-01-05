/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:46:39 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/26 02:16:45 by mdalkili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "src/game/minilibx-linux/mlx.h"
//STRING UTILS
int		string_len(char *string);
char 	*string_dup(char *string);
//EXTENSION_CONTROL
int		extension_control(char *name);
void	extension_error(int type);
//MAP
typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**matrix;
	int		matrix_current_row;
} t_map;
typedef struct s_window_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_window_data;
typedef struct s_ray
{
	int x1;
	int	x2;
	int y1;
	int y2;
	int color;
} t_ray;
typedef struct s_player
{
	int	state;
	double	p_x;
	double	p_y;
	int	size;
	int	color;
	t_ray *rays;
	double fov;
	double angle;
} t_player;
typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		cell_size;
	int		max_ray;
	int		ray_color;
	t_window_data window_data;
	t_player *player;
} t_game;
//EVENT CODE
typedef enum s_event_code
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
} t_event_code;
typedef enum s_event_mask
{
	KEYPRESS_MASK=1L<<0,
	KEYRELEASE_MASK=1L<<1
} t_event_mask;
typedef enum s_keycode
{
	RIGHT_ARROW=65363,
	LEFT_ARROW=65361,
	UP_ARROW=65362,
	DOWN_ARROW=65364
} t_keycode;
//EVENT FUNCTIONS
void	start_events(t_game *game);
int		close_window(void *param);
int		move(int keycode, void *param);
//MAP FUNCTIONS
void	read_and_parse_map(char *path, t_map *map);
void	parse_map(t_map *map, char *line);
//GAME
void	start_game(t_game *game);
void	draw_map_2d(t_game *game);
void	draw_player(t_game *game);
//DRAW FUNCTION
void draw_line(t_game *game, double x1,double x2, double y1,double y2,int color);
//FREE
void free_game(t_game *game);
enum	e_extension_error_types
{
	LENGTH,
	HIDDEN,
	EXTENSION_NAME
};
enum	e_MAP_PARSE_TYPES
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ROW
};
#endif