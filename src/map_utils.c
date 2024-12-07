/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:27:23 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/12/06 14:57:19 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	file_control(t_parse *map, char *str)
{
	int	fd;
    
   map->map = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", "file could not be opened\n");
		exit(1);
	}
	else
		return (fd);
}

char	**file_read_utils(t_parse *map, char *text, int fd)
{
	char	**maps;

	map->map_text = ft_strdup(text);
	maps = ft_split(text, '\n');
	free(text);
	if (!maps)
	{
		close(fd);
		printf("%s\n","Failed to split text into map");
		exit(1);
	}
	//printf("%s\n",map->map_text);
	//printf("%s\n",maps[2]);
	return (maps);
}
void	map_char_control_utils(t_parse *game, int *map_index, int *i, int *c)
{
	if (game->map[*map_index][*i] == 'N' || game->map[*map_index][*i] == 'S'
		|| game->map[*map_index][*i] == 'W'
		|| game->map[*map_index][*i] == 'E')
		(*c)++;
	if (game->map[*map_index][*i] != '1' && game->map[*map_index][*i] != '0'
		&& game->map[*map_index][*i] != 'N'
		&& game->map[*map_index][*i] != ' '
		&& game->map[*map_index][*i] != '\0'
		&& game->map[*map_index][*i] != 'S'
		&& game->map[*map_index][*i] != 'W'
		&& game->map[*map_index][*i] != 'E')
	{
		printf("%s\n","char error");
		exit(1);
	}
}
void	map_char_control(t_parse *game)
{
	int	map_index;
	int	player_count;
	int	i;

	map_index = 6;
	player_count = 0;
	while (game->map[map_index])
	{
		i = 0;
		while (game->map[map_index][i])
		{
			map_char_control_utils(game, &map_index, &i, &player_count);
			i++;
		}
		map_index++;
	}
	if (player_count != 1)
	{
		printf("%s\n","player count error");
		exit(1);
	}
}
char *copy_strdup(const char *s)
{
    char *d = malloc(ft_strlen(s) + 1);
    if (d == NULL) return NULL;
    ft_strlcpy(d, s, ft_strlen(s) + 1);
    return d;
}

void read_xpm(t_parse *parse)
{
    char *line = parse->map_text;
    char *next_line;
	
    while (line && *line)
    {
        next_line = ft_strchr(line, '\n');
        if (next_line)
        {
            *next_line = '\0';
            next_line++;
        }

        if (line[0] != '\n' && line[0] != '\0')
        {
            if (ft_strncmp(line, "NORTH", 5) == 0){
                parse->north = copy_strdup(line + 6); // 6: "NORTH " (5 harf + 1 boşluk)
				printf("%s\n",parse->north);}
            else if (ft_strncmp(line, "SOUTH", 5) == 0)
                parse->south = ft_strdup(line + 6); // 6: "SOUTH " (5 harf + 1 boşluk)
            else if (ft_strncmp(line, "WEST", 4) == 0)
                parse->west = ft_strdup(line + 5);  // 5: "WEST " (4 harf + 1 boşluk)
            else if (ft_strncmp(line, "EAST", 4) == 0)
                parse->east = ft_strdup(line + 5);  // 5: "EAST " (4 harf + 1 boşluk)
        }

        line = next_line;
    }
}
void read_xpmmm(t_parse *parse)
{
	 int i = 0;
    while (parse->map[i] != NULL)
    {
        char *line = parse->map[i];
        if (ft_strncmp(line, "NO ", 3) == 0)
            parse->north = ft_strdup(line + 3);
        else if (ft_strncmp(line, "SO ", 3) == 0)
            parse->south = ft_strdup(line + 3);
        else if (ft_strncmp(line, "WE ", 3) == 0)
        	parse->west = ft_strdup(line + 3);
        else if (ft_strncmp(line, "EA ", 3) == 0)
            parse->east = ft_strdup(line + 3);
        else if (ft_strncmp(line, "C ", 2) == 0)
			parse->c = ft_strdup(line + 2);
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse->f = ft_strdup(line + 2);
		else
			break;
        i++;
    }
}

void	xpm_control(t_parse *parse)
{
	int	*fd;
	int	i;
	
	fd = malloc(sizeof(int) * 4);
	i = 0;
	fd[0] = open(parse->north, O_RDONLY);
	fd[1] = open(parse->south, O_RDONLY);
	fd[2] = open(parse->west, O_RDONLY);
	fd[3] = open(parse->east, O_RDONLY);
	while (i < 4)
	{
		i++;
	}
	free(fd);
	name_xpm(parse);
}
void	map_division_utils(t_parse *parse, char *map_copy)
{
	int	i;
	int	j;

	i = -1;
	while (parse->map_text[++i] != '\0')
	{
		if (parse->map_text[i] == ' ' || parse->map_text[i] == '\t')
		{
			i++;
			continue ;
		}
		if (parse->map_text[i] == '\n' || parse->map_text[i] == '\t')
		{
			j = i + 1;
			while (parse->map_text[j] == ' ' || parse->map_text[j] == '\t')
				j++;
			if (parse->map_text[i + 1] == '\n' || parse->map_text[j] == '\n')
			{
				printf("%s\n","map division error");
				free(map_copy);
				exit(1);
			}
		}
	}
	free(map_copy);
}


void	map_division_control(t_parse *parse)
{
	int		i;
	int		j;
	char	*map_copy;

	map_copy = malloc(sizeof(char) * ft_strlen(parse->map_text) + 1);
	i = 0;
	j = 0;
	while (parse->map_text[i])
	{ 
		if (parse->map_text[i] == 'C')
			break ;
		i++;
	}
	while (parse->map_text[i] != '\n')
		i++;
	while (parse->map_text[i] == '\n')
		i++;
	while (parse->map_text[i] != '\0')
		map_copy[j++] = parse->map_text[i++];
	free(parse->map_text);
	parse->map_text = ft_strtrim(map_copy, "\n");
	map_division_utils(parse, map_copy);
}
