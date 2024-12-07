/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olcayyetiskin <olcayyetiskin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:14:51 by olcayyetisk       #+#    #+#             */
/*   Updated: 2024/11/30 23:11:31 by olcayyetisk      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


int main(int ac,char **av)
{
    if (ac == 2)
    {
        t_parse *map;
        map = malloc(sizeof(t_parse));
        map_start(map, av[1]);
    }
    else
    {
        write(1, " ac az var Error\n", 6);
        return (0);
    }
}