/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:36:20 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 20:56:12 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	sublen;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((ft_strlen(s) - start) > len && start < ft_strlen(s))
		sublen = len;
	else
		sublen = ft_strlen(s) - start;
	i = 0;
	sub = malloc((sublen + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	while (i < sublen)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
