/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:10:48 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/18 18:28:25 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	handle_invalid_character(t_map	*map)
{
	parse_error(map, "Error: Invalid character\n");
	free(map->line);
}

void	parse_error(t_map *map, char *message)
{
	ft_printf(message);
	if (map->map_tab)
		free_double_array(map->map_tab);
	if (map->line)
		free(map->line);
	if (map->map_line)
		free(map->map_line);
	free_rgb_texture(map);
	exit (EXIT_FAILURE);
}

void	size_map(t_map *map)
{
	int	i;

	i = 0;
	size(map, map->map_tab, 0, 0);
	if (map->height_map == 0 && map->width_map == 0)
		parse_error(map, "map height and width error\n");
	while (map->map_tab[i])
	{
		if (cub_strlen(map->map_tab[i]) <= map->width_map)
		{
			map->map_tab[i] = new_liner(map->map_tab[i], map->width_map);
			if (!map->map_tab[i])
				parse_error(map, "Error\nMalloc error\n");
		}
		i++;
	}
}

void	process_line(t_map	*map)
{
	if (map->line[0] == '\n')
		map->line[0] = ' ';
	if (check_rgb_texture(map, map->line) == 1)
	{
		if (ft_strchr(map->line, '-'))
		{
			handle_invalid_character(map);
			return ;
		}
		map->map_line = cub_strjoin(map->map_line, map->line);
	}
	free(map->line);
}

void	read_map(int fd, t_map *map)
{
	while (1)
	{
		map->line = get_next_line(fd);
		if (!map->line)
			break ;
		process_line(map);
	}
	map->map_tab = ft_split(map->map_line, '-');
	free(map->map_line);
	map->map_line = NULL;
	size_map(map);
}
