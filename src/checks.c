/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:37:38 by olyetisk          #+#    #+#             */
/*   Updated: 2024/11/10 17:45:15 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_extension(char *str)
{
	int i;
	i = ft_strlen(str);
	if(i > 4 && str[i - 1] == 'b' && str[i - 2] == 'u' && str[i - 3] == 'c' && str[i - 4] == '.')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int check_undefined(char **map)
{
	int i;
	int j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
 			if (ft_strchr("10WSNE ", map[i][j]) == NULL)
			{
				printf("Undefined char '%c' in map!\n", map[i][j]);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (1);
}