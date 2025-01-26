/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:26:26 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:47:41 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <dirent.h>
# include <limits.h>
# include "../libft/libft.h"

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define SPACE			32

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_L			65361
# define KEY_R			65363

enum	e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

typedef struct s_img
{
	void	*mlx_img;
	char	*path;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_map
{
	void	*mlx;
	void	*mlx_win;
	t_img	img[5];
	int		display_width;
	int		display_height;

	char	**map_tab;
	int		width_map;
	int		height_map;

	char	p_dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	int		rgb_floor[3];
	int		rgb_sky[3];

	char	*line;
	char	*map_line;

	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;

	double	ray_dir_x;
	double	ray_dir_y;
	double	cam_x;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perpwalldist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		wall_side;
	int		wall_dist;
	int		size_line;
	int		start_line;
	int		end_line;
	int		start;
	int		end;
	double	speed;
	double	rot_speed;

}	t_map;

void	default_zero(t_map *map);
int		pars(char *argv);
void	destroy_image(t_map *map);
void	free_rgb_texture(t_map *map);
void	free_double_array(char **str);
int		close_game(t_map *map);
void	parse_error(t_map *map, char *message);
int		map_name(char *argv);
void	read_map(int fd, t_map *map);
int		start(t_map *map, int fd);
int		check_valid(char c, char *valid_char);
int		cub_strlen(char *str);
char	*new_liner(char *str, int size);
char	*cub_strjoin(char *s1, char *s2);
void	load_image(t_map *map, int index);
int		wall_check(t_map *map);
void	check_p_p(t_map *map, char direction, int i, int j);
void	size(t_map *map, char **array, int i, int j);
int		check_rgb_texture(t_map *map, char *line);
void	texture_road(t_map *map, char **path, char **space_liner);
int		comma_rgb(char *line);
int		check_rgb(int *rgb, char *line);
void	rgb_road(t_map *map, int *rgb, char **split_line);
void	create_empty_image(t_map *map, int index, int width, int height);
int		key_hook(int keycode, t_map *map);
int		mouse_hook(int x, int y, t_map *map);
void	game_error(t_map *map, char *message);
void	ft_init_game_stat(t_map *map);
void	init_image(t_map *map);
int		ft_init_game(t_map *map);
void	initialize_image_address(t_map *map, int index);
void	move(t_map *map, double next_x, double next_y, char sign);
void	rotate(t_map *map, double rot_spd);
void	rotate_east_west(t_map *map, double rot_spd);
void	delta_distance(t_map *map);
void	get_step(t_map *map);
void	digital_differential_analyser(t_map *map);
void	init_raycasting(t_map *map, int x);
void	raycasting(t_map *map);
int		get_color(t_map *map, int x, int y, int i);
void	img_put_pixel(t_map *map, int x, int y, int color);
void	draw_columnn(t_map *map, int x);
void	draw_texture(t_map *map, int start, int line_height);
int		render(t_map *map);
int		create_rgb(int t, int r, int g, int b);
void	render_background(t_map *map);
int		render(t_map *map);

#endif