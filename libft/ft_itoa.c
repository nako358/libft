/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htakayam <htakayam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:35:12 by htakayam          #+#    #+#             */
/*   Updated: 2024/05/01 18:57:53 by htakayam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	ft_insert_num(char *result, int n, int d, int *i)
{
	while (n > 0)
	{
		result[d - 1] = n % 10 + '0';
		n /= 10;
		(*i)++;
		d--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		d;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	d = ft_digits(n);
	if (n >= 0)
		result = malloc(sizeof(char) * (d + 1));
	else
		result = malloc(sizeof(char) * (d + 2));
	if (!result)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		result[i++] = '-';
		n = -n;
	}
	ft_insert_num(&result[i], n, d, &i);
	result[i] = '\0';
	return (result);
}
