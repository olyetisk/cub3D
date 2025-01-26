/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:06:44 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:21:24 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	texture_road(t_map *map, char **path, char **space_liner)
{
	int	i;

	i = 0;
	while (space_liner[i])
		i++;
	if (i == 3 && space_liner[2][0] == '\n')
		free(space_liner[i--]);
	if (i != 2 || *path)
	{
		free_double_array(space_liner);
		parse_error(map, "texture line error\n");
	}
	*path = ft_strjoin(*path, space_liner[1]);
	if (path[0][cub_strlen(*path)] == '\n')
		path[0][cub_strlen(*path)] = '\0';
	free_double_array(space_liner);
}

int	comma_rgb(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (!ft_isdigit(line[0]) || !ft_isdigit(line[cub_strlen(line) - 1])
		|| cub_strlen(line) > 11)
		return (0);
	while (line[i + 1])
	{
		if (line[i] == ',')
			comma++;
		if (line[i] == ',' && line[i + 1] && line[i + 1] == ',')
			return (0);
		else if ((!ft_isdigit(line[i])) && line[i] != ',')
			return (0);
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

int	check_rgb(int *rgb, char *line)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	if (!comma_rgb(line))
		return (0);
	while (line[i])
	{
		if (i == 0)
			rgb[0] = ft_atoi(line);
		else if (line[i] == ',')
			rgb[j++] = ft_atoi(line + i + 1);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

void	rgb_road(t_map *map, int *rgb, char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		i++;
	if (i == 3 && split_line[2][0] == '\n')
		free(split_line[i--]);
	if ((i != 2) || !check_rgb(rgb, split_line[1]))
	{
		free_double_array(split_line);
		parse_error(map, "Error\nRGB line is incorrect\n");
	}
	free_double_array(split_line);
}
