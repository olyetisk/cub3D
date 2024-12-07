/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:10:02 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/06 14:46:41 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"

typedef struct	s_parse
{
    char    **map;
    char    *map_text;
    char    **copy_map;
    char    *north;
    char    *south;
    char    *west; 
    char    *east;
    char    *f;
    char    *c;
    int		max_size;
    
}				t_parse;




//*****************************PARSE************************************
void	map_name(char *map_name);
void	map_start(t_parse *map, char *str);
void	xpm_control(t_parse *parse);
void	map_division_control(t_parse *parse);
void	name_xpm(t_parse *parse);
void	fill_x_map(t_parse *parse);
void	copy_map(t_parse *game);
void    read_xpm(t_parse *parse);
char    *copy_strdup(const char *s);
void	map_char_control_utils(t_parse *game, int *map_index, int *i, int *c);
void	map_char_control(t_parse *map);
int	    file_control(t_parse *map, char *str);
char	**read_map(t_parse *map, int fd);
char	**file_read_utils(t_parse *map, char *text, int fd);
void    read_xpmmm(t_parse *parse);

#endif