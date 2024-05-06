/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:54:29 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/28 20:13:06 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	begin_num(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				i++;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		k;

	if (!s1)
		return (NULL);
	i = begin_num(s1, set);
	k = ft_strlen(s1) - 1;
	while (s1[k])
	{
		j = 0;
		while (set[j])
		{
			if (s1[k] == set[j])
			{
				k--;
				break ;
			}
			j++;
		}
		if (j == ft_strlen(set))
			break ;
	}
	return (ft_substr(s1, i, k - i + 1));
}
