/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:06:51 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/18 16:13:13 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_p_p(t_map *map, char direction, int i, int j)
{
	map->pos_y = (double)i;
	map->pos_x = (double)j;
	map->p_dir = direction;
	if (direction == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
	}
	else if (direction == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
	}
	else if (direction == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
	}
	else if (direction == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
	}
}

void	size(t_map *map, char **array, int i, int j)
{
	int	tmp;
	int	count_player;

	tmp = 0;
	count_player = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (check_valid(array[i][j], "NSEW"))
			{
				check_p_p(map, array[i][j], i, j);
				count_player++;
			}
			j++;
		}
		if (j > tmp)
			tmp = j;
		i++;
	}
	if (count_player != 1)
		return ;
	map->width_map = tmp;
	map->height_map = i;
}

void	check_stat(t_map *map)
{
	int	i;

	i = 0;
	if (!map->img[0].path || !map->img[1].path
		|| !map->img[2].path || !map->img[3].path)
		parse_error(map, "Error\nMissing textures\n");
	while (i < 3)
	{
		if (map->rgb_floor[i] == -1 || map->rgb_sky[i] == -1)
			parse_error(map, "Error\nMissing colors\n");
		i++;
	}
}

int	check_rgb_texture(t_map *map, char *line)
{
	static int	i = 0;

	while (i < 6)
	{
		if (line[0] == ' ' && !line[1])
			return (0);
		if (!ft_strncmp(line, "NO ", 3))
			texture_road(map, &map->img[0].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "SO ", 3))
			texture_road(map, &map->img[1].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "WE ", 3))
			texture_road(map, &map->img[2].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "EA ", 3))
			texture_road(map, &map->img[3].path, ft_split(line, ' '));
		else if (!ft_strncmp(line, "F ", 2))
			rgb_road(map, map->rgb_floor, ft_split(line, ' '));
		else if (!ft_strncmp(line, "C ", 2))
			rgb_road(map, map->rgb_sky, ft_split(line, ' '));
		else
			parse_error(map, "Error\nIncorrect data on texture/color\n");
		i++;
		return (0);
	}
	check_stat(map);
	return (1);
}
