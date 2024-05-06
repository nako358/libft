/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:49:47 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/24 13:42:52 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	s1_cpy = malloc(sizeof(char) * (len + 1));
	if (!s1_cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}
