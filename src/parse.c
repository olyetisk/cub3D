/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:29 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/06 14:52:06 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	map_start(t_parse *map, char *str)
{
	int	fd;

	map_name(str);
	fd = file_control(map, str);
	map->map = read_map(map, fd);
	map_char_control(map);
	copy_map(map);
	read_xpmmm(map);
	//read_xpm(map);
	xpm_control(map);
	map_division_control(map);
	fill_x_map(map);
}