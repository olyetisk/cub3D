/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:07:47 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/22 20:07:48 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move(t_map *map, double next_x, double next_y, char sign)
{
	if (sign == '+')
	{
		if (map->map_tab[(int)map->pos_y][(int)(map->pos_x + next_x)] != '1')
			map->pos_x += next_x;
		if (map->map_tab[(int)(map->pos_y + next_y)][(int)map->pos_x] != '1')
			map->pos_y += next_y;
	}
	else if (sign == '-')
	{
		if (map->map_tab[(int)map->pos_y][(int)(map->pos_x - next_x)] != '1')
			map->pos_x -= next_x;
		if (map->map_tab[(int)(map->pos_y - next_y)][(int)map->pos_x] != '1')
			map->pos_y -= next_y;
	}
}

void	rotate(t_map *map, double rot_spd)
{
	double	tmp_dir_x;
	double	tmp_plane_x;

	tmp_dir_x = map->dir_x;
	tmp_plane_x = map->plane_x;
	map->dir_x = map->dir_x * cos(rot_spd) - map->dir_y * sin(rot_spd);
	map->dir_y = tmp_dir_x * sin(rot_spd) + map->dir_y * cos(rot_spd);
	map->plane_x = map->plane_x * cos(rot_spd) - map->plane_y * sin(rot_spd);
	map->plane_y = tmp_plane_x * sin(rot_spd) + map->plane_y * cos(rot_spd);
}
