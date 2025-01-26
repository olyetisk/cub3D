/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:24:34 by olcayyetisk       #+#    #+#             */
/*   Updated: 2025/01/19 12:50:49 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
/*
   int     main(void)
   {
   char    *s1 = "Hello test test";
   char    *tab;

   tab = ft_strdup(s1);
   printf("copy = %s\n", tab);
   printf("original = %s\n", s1);
   free(tab);
   }
   */
