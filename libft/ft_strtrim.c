/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:20:24 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 20:56:16 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocate(int start, int end, const char *s1)
{
	char	*str;
	int		i;
	int		size;

	size = end - start + 1;
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	in_set(const char *set, char c)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start])
	{
		if (in_set(set, s1[start]))
			start++;
		else
			break ;
	}
	while (s1[end] && end >= start)
	{
		if (in_set(set, s1[end]))
			end--;
		else
			break ;
	}
	trim = allocate(start, end, s1);
	return (trim);
}
