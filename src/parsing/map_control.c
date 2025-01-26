/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:06:34 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/18 17:58:09 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	vertical_1(char **column, int y, int x, int size_y)
{
	while (y < size_y)
	{
		if (y == 0 && !check_valid(column[y][x], "1 "))
			return (0);
		if (!check_valid(column[y][x], "10NSEW "))
			return (0);
		if (column[y][x] == ' ')
		{
			if (y > 0 && column[y - 1][x] != '1')
				return (0);
			while (y < size_y && column[y][x] == ' ')
				y++;
			if (y < size_y && column[y][x] != '1')
				return (0);
		}
		if (y < size_y)
			y++;
	}
	if (!check_valid(column[y - 1][x], "1 "))
		return (0);
	return (1);
}

int	vertical_check(t_map *map, int y, int x)
{
	while (map->map_tab[y][x])
	{
		if (!vertical_1(map->map_tab, y, x, map->height_map))
			return (0);
		x++;
	}
	return (1);
}

int	horizontal_1(t_map *map, char *line, int x)
{
	while (line[x])
	{
		if (x == 0 && !check_valid(line[x], "1 "))
			return (0);
		if (!check_valid(line[x], "10NSEW "))
			parse_error(map, "Error\nInvalid character on map\n");
		if (line[x] == ' ')
		{
			if (x > 0 && line[x - 1] != '1')
				return (0);
			while (line[x] && line[x] == ' ')
				x++;
			if (line[x] && line[x] != '1')
				return (0);
		}
		if (line[x])
			x++;
	}
	if (!check_valid(line[x - 1], "1 "))
		return (0);
	return (1);
}

int	horizontal_check(t_map *map, int y, int x)
{
	while (map->map_tab[y])
	{
		if (!horizontal_1(map, map->map_tab[y], x))
			return (0);
		y++;
	}
	return (1);
}

int	wall_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (!horizontal_check(map, y, x) || !vertical_check(map, y, x))
	{
		free_rgb_texture(map);
		return (0);
	}
	return (1);
}
