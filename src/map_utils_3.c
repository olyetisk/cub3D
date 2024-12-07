/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:01:52 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/01 16:02:33 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_x_map(t_parse *parse)
{
    int		x;
    int		y;
    size_t	len;

    if (parse->copy_map == NULL)
        return;

    x = -1;
    while (parse->copy_map[++x] != NULL)
    {
        y = -1;
        while (parse->copy_map[x][++y] != '\0')
        {
            if (parse->copy_map[x][y] == ' ' || parse->copy_map[x][y] == '\t')
                parse->copy_map[x][y] = 'X';
        }
    }

    x = 0;
    len = 0;
    while (parse->copy_map[x] != NULL)
    {
        size_t current_len = ft_strlen(parse->copy_map[x]);
        if (current_len > len)
            len = current_len;
        x++;
    }
    parse->max_size = len;
}
