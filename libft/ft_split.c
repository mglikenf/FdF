/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:40:00 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 20:55:02 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		nword;
	int		start;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nword = word_count(s, c);
	(strings = (char **)malloc((nword + 1) * sizeof(char *)));
	if (!strings)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < nword)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		strings[j++] = ft_substr(s, start, i - start);
	}
	strings[j] = 0;
	return (strings);
}
