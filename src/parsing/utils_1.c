/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:22:36 by olyetisk          #+#    #+#             */
/*   Updated: 2025/01/18 17:49:58 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error_map(t_map *map)
{
	if (!wall_check(map))
	{
		ft_printf("Error\nMap not closed\n");
		return (0);
	}
	return (1);
}

char	*cub_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = (cub_strlen(s1) + cub_strlen(s2));
	tab = malloc(sizeof(char) * size + 2);
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	tab[size] = '-';
	tab[size + 1] = '\0';
	if (s1)
		free(s1);
	return (tab);
}

int	start(t_map	*map, int fd)
{
	read_map(fd, map);
	if (!error_map(map))
		return (0);
	close(fd);
	return (1);
}
