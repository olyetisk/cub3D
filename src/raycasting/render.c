/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:07:24 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:56:13 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_background(t_map *map)
{
	int	x;
	int	y;

	if (!map)
	{
		fprintf(stderr, "Error: map or map->img is NULL\n");
		exit(1);
	}
	x = 0;
	while (x < map->display_width)
	{
		y = 0;
		while (y < map->display_height)
		{
			if (y < map->display_height / 2)
				img_put_pixel(map, x, y, create_rgb(0, map->rgb_sky[0],
						map->rgb_sky[1], map->rgb_sky[2]));
			else
				img_put_pixel(map, x, y, create_rgb(0, map->rgb_floor[0],
						map->rgb_floor[1], map->rgb_floor[2]));
			y++;
		}
		++x;
	}
}

int	render(t_map *map)
{
	if (!map->mlx || !map->mlx_win)
	{
		fprintf(stderr, "Error: mlx or mlx_win is NULL\n");
		exit(1);
	}
	render_background(map);
	raycasting(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img[4].mlx_img, 0, 0);
	return (0);
}

int	get_color(t_map *map, int x, int y, int i)
{
	return (*(int *)(map->img[i].addr
		+ (y * map->img[i].line_len + x * (map->img[i].bpp / 8))));
}
