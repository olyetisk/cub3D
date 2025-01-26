/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:07:37 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:54:18 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	game_error(t_map *map, char *message)
{
	ft_printf(message);
	free_rgb_texture(map);
	free_double_array(map->map_tab);
	destroy_image(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(EXIT_FAILURE);
}

void	init_image(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		load_image(map, i);
		i++;
	}
	create_empty_image(map, 4, map->display_width, map->display_height);
	i = 0;
	while (i < 5)
	{
		initialize_image_address(map, i);
		i++;
	}
}

void	ft_init_game_stat(t_map *map)
{
	map->speed = 0.09;
	map->rot_speed = 0.09;
	map->display_width = 800;
	map->display_height = 600;
	if (map->p_dir == 'N')
	{
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
	if (map->p_dir == 'S')
	{
		map->plane_x = -0.66;
		map->plane_y = 0;
	}
	if (map->p_dir == 'W')
	{
		map->plane_x = 0;
		map->plane_y = 0.66;
	}
	if (map->p_dir == 'E')
	{
		map->plane_x = 0;
		map->plane_y = -0.66;
	}
}

int	ft_init_game(t_map *map)
{
	ft_init_game_stat(map);
	map->mlx = mlx_init();
	if (!map->mlx)
		game_error(map, "Error\nInitialisation of display has failed\n");
	map->mlx_win = mlx_new_window(map->mlx, map->display_width,
			map->display_height, "Cub3D");
	if (!map->mlx_win)
		game_error(map, "Error\nInitialisation of window has failed\n");
	init_image(map);
	if (!map->mlx || !map->mlx_win || !map->img[4].mlx_img)
		game_error(map, "Error\nInvalid image or window reference\n");
	mlx_loop_hook(map->mlx, &render, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 6, 1L << 6, mouse_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_game, map);
	mlx_loop(map->mlx);
	return (0);
}
