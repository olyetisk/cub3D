/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:06:51 by olyetisk          #+#    #+#             */
/*   Updated: 2024/11/10 17:40:15 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line_bonus.h"
# include "libft.h"


typedef struct s_parse
{
	char **map;
	char *map_path;
	char **map_copy;
	
} t_parse;
//------------------------------  MAP  ----------------------------------------

int		check_extension(char *str);
char	**getmap(char *av);
int		map_len(char *av);
int		check_undefined(char **map);

# endif