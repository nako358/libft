/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:51:58 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/01 16:28:18 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_spliter(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

int	ft_count_spliter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	ft_free(char **result, int i)
{
	while (i-- >= 0)
		free(result[i]);
	return (0);
}

int	ft_spliter(char const *s, char c, char **result)
{
	int		i;
	int		end;
	int		start;

	i = 0;
	end = 0;
	while (s[end])
	{
		if (ft_check_spliter(s[end], c) == 1)
			end++;
		else
		{
			start = end;
			while (ft_check_spliter(s[end], c) == 0)
				end++;
			result[i] = (char *)malloc(sizeof(char) * (end - start + 1));
			if (!result[i])
				return (ft_free(&*result, i));
			ft_strlcpy(result[i], s + start, end - start + 1);
			i++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count_spliter(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!ft_spliter(&*s, c, &*result))
	{
		free(result);
		return (NULL);
	}
	result[count] = NULL;
	return (result);
}
