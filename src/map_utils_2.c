/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:53:04 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/06 14:54:00 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	copy_map(t_parse *game)
{
	int	i;
	int	j;
	int	map_index;

	map_index = 6;
	i = 0;
	j = map_index;
	while (game->map[j++])
		i++;
	game->copy_map = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (game->map[map_index])
	{
		game->copy_map[i] = ft_strdup(game->map[map_index]);
		i++;
		map_index++;
	}
	game->copy_map[i] = NULL;
}
void	name_xpm(t_parse *parse)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (parse->map[i] != NULL && i < 4)
	{
		len = ft_strlen(parse->map[i]);
		if (parse->map[i][len - 1] != 'm' || parse->map[i][len - 2] != 'p'
			|| parse->map[i][len - 3] != 'x' || parse->map[i][len - 4] != '.')
		{
			printf("%s\n", "xpm name error");
			exit(0);
		}
		i++;
	}
}
