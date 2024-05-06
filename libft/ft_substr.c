/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:05:42 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/02 22:16:52 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*subs;
	size_t			size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start || len == 0)
	{
		subs = (unsigned char *)malloc(1);
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return ((char *)subs);
	}
	if (size - start >= len)
		size = len;
	subs = malloc(1 * (size + 1));
	if (!subs)
		return (NULL);
	ft_strlcpy((char *)subs, s + start, size + 1);
	return ((char *)subs);
}
