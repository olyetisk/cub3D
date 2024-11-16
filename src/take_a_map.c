/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:23:25 by olyetisk          #+#    #+#             */
/*   Updated: 2024/11/10 16:21:13 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_len(char *av)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		printf("Can not open map\n",EXIT_FAILURE);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
		{
			break ;
		}
		free(s);
		i++;
	}
	close (fd);
	return (i);
}

char	**getmap(char *av)
{
	char	**s;
	int		i;
	int		fd;
	int		len;

	len = map_len(av);
	i = 0;
	s = malloc(sizeof(char *) * (len + 1));
	if (!s)
	{
		exit (EXIT_FAILURE);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		free (s);
		printf("Can not open map\n",EXIT_FAILURE);
	}
	while (len > i)
	{
		s[i++] = get_next_line (fd);
	}
	s[i] = NULL;
	close (fd);
	return (s);
}
