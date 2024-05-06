/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:21:01 by htakayam          #+#    #+#             */
/*   Updated: 2024/04/28 19:01:32 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

const char	*ft_strplus(const char *str, int *sign)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	unsigned long	ans;
	int				sign;

	sign = 1;
	ans = 0;
	str = ft_strplus(str, &sign);
	while ('0' <= *str && *str <= '9')
	{
		if (((unsigned long)LONG_MAX - (*str - '0')) / 10 < ans && sign == 1)
			return ((int)LONG_MAX);
		if (((unsigned long)LONG_MIN - (*str - '0')) / 10 < ans && sign == -1)
			return ((int)LONG_MIN);
		ans = 10 * ans + *str - '0';
		str++;
	}
	return ((int)ans * sign);
}
