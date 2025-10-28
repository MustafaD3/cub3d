/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdalkili <mdalkilic344@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 03:46:39 by mdalkili          #+#    #+#             */
/*   Updated: 2025/10/23 19:37:11 by mdalkili         ###   ########.fr       */
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
char 	*string_dup(char *string);
//EXTENSION_CONTROL
int		extension_control(char *name);
void	extension_error(int type);
//MAP
char	*open_and_read_map(char *path);
enum	e_extension_error_types
{
	LENGTH,
	HIDDEN,
	EXTENSION_NAME
};
#endif