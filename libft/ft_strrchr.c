/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:47:08 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 20:56:20 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	ch;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (str[i])
		i++;
	if (str[i] == ch && ch == '\0')
		return (&str[i]);
	while (i-- > 0)
	{
		if (str[i] == ch)
			return (&str[i]);
	}
	return (NULL);
}
