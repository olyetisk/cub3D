/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:25:19 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:48:32 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	search;

	search = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != search)
		len--;
	if (s[len] == search)
		return ((char *)s + len);
	else
		return (NULL);
}
