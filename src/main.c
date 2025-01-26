/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:07:06 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 13:01:58 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_name(char *argv)
{
	int			len;
	const char	*extension;

	extension = ".cub";
	len = strlen(argv);
	if (strcmp(&argv[len - 4], extension) != 0)
	{
		printf("error: wrong name.\n");
		exit (EXIT_FAILURE);
	}
	return (1);
}

int	pars(char *argv)
{
	int		fd;
	int		result;
	char	test[1];

	fd = open(argv, O_RDONLY);
	result = read(fd, test, 1);
	if (result <= 0)
	{
		if (result == 0)
			ft_printf("Error\nEmpty file\n");
		else if (result < 0)
			ft_printf("Error\nInvalid entry\n");
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	default_zero(&map);
	if (ac != 2)
		parse_error(&map, "arg error\n");
	map_name(av[1]);
	pars(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nFailed to open file\n");
		return (1);
	}
	if (!start(&map, fd))
	{
		free_double_array(map.map_tab);
		return (1);
	}
	ft_init_game(&map);
	return (0);
}
