/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:44:41 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/10 16:31:28 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	str = (char *)s;
	ch = (char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (&str[i]);
		i++;
	}
	if (str[i] == ch && ch == '\0')
		return (&str[i]);
	return (NULL);
}
