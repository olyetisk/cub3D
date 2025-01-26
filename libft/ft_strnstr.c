/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:25:13 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:39:53 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == *little)
		{
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0
				&& ft_strlen(little) + i <= len)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
