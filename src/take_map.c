/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:20:00 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/11/20 15:45:01 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void	map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (!(map_name[len - 1] == 'b' && map_name[len - 2] == 'u'
				&& map_name[len - 3] == 'c' && map_name[len - 4] == '.'))
		{
			printf("%s\n", "map name error");
			exit(1);
		}
	}
	else
	{
		printf("%s\n", "map name error");
		exit(1);
	}
}

char	**read_map(t_parse *map, int fd)
{
	char	*text;
	char	*a;
	char	*tmp;

	text = get_next_line(fd);
	if (!text)
	{
		close(fd);
		printf("%s\n", "file could not be opened\n");
		exit(1);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		a = ft_strdup(text);
		free(text);
		text = ft_strjoin(a, tmp);
		free(tmp);
		free(a);
	}
	return (file_read_utils(map, text, fd));
}
