/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:18:20 by olyetisk          #+#    #+#             */
/*   Updated: 2024/11/16 16:32:37 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
	t_parse parse;
	if (ac != 2)
		return (printf("Error\n"), EXIT_FAILURE);
	check_extension(av[0]);
	parse.map_path = av[1];
	parse.map = getmap(parse.map_path);
	parse.map_copy = parse.map;
	check_undefined(parse.map_copy);
	printf("%s\n",parse.map[0]);
}

