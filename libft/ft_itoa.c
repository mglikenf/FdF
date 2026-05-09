/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:16:41 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/10 16:30:51 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i = 1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	int			j;
	long int	num;

	num = n;
	size = count_digits(num);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	j = 0;
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
		j++;
	}
	while (size > j)
	{
		size--;
		str[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
