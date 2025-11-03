/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:46:39 by mdalkili          #+#    #+#             */
/*   Updated: 2025/11/02 04:47:53 by mdalkili         ###   ########.fr       */
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
//STRING UTILS
int		string_len(char *string);
int		string_find_char(char *string, char chr, int position);
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
} t_map;
void	open_and_read_map(char *path, t_map *map);
void	parse_direction(t_map *map, char *temp);
enum	e_extension_error_types
{
	LENGTH,
	HIDDEN,
	EXTENSION_NAME
};
#endif