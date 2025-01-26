/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:13:48 by olyetisk          #+#    #+#             */
/*   Updated: 2025/01/19 12:53:37 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_image(t_map *map, int index)
{
	map->img[index].mlx_img = mlx_xpm_file_to_image(map->mlx,
			map->img[index].path, &map->img[index].w, &map->img[index].h);
	if (!map->img[index].mlx_img)
		game_error(map, "Error\nPath texture is incorrect\n");
}

void	create_empty_image(t_map *map, int index, int width, int height)
{
	map->img[index].mlx_img = mlx_new_image(map->mlx, width, height);
	if (!map->img[index].mlx_img)
		game_error(map, "Error\nImage initialization has failed\n");
}

void	initialize_image_address(t_map *map, int index)
{
	map->img[index].addr = mlx_get_data_addr(map->img[index].mlx_img,
			&map->img[index].bpp, &map->img[index].line_len,
			&map->img[index].endian);
	if (!map->img[index].addr)
		game_error(map, "Error\nImage initialization has failed\n");
}
