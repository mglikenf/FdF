/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:16:13 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/10 16:31:06 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d <= s && s < d + n)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (d);
}
