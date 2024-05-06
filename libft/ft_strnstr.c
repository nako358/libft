/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:00:05 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/27 15:05:01 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_nee;

	len_nee = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	if ((!haystack && needle) && (len == 0))
		return (NULL);
	i = 0;
	while (*haystack && i + len_nee <= len)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(haystack, needle, len_nee) == 0)
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (0);
}
