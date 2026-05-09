/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:26:41 by mglikenf          #+#    #+#             */
/*   Updated: 2024/02/20 14:26:43 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	process_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	while (line[i])
	{
		i++;
		line[i] = '\0';
	}
}

char	*extract_next_line(char *line)
{
	char	*next_line;
	int		i;
	int		len;

	next_line = NULL;
	i = 0;
	if (ft_strchr(line, '\n'))
	{
		while (line[i] && line[i] != '\n')
			i++;
		if (i + 1 < (int)ft_strlen(line))
		{
			len = ft_strlen(line) - (i + 1);
			next_line = ft_substr(line, i + 1, len);
		}
	}
	return (next_line);
}

char	*read_line(int fd, char *buffer, char *next_line)
{
	ssize_t	nread;
	char	*line;

	nread = 1;
	while (nread > 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if ((int)nread == 0)
			break ;
		else if ((int)nread == -1)
			return (0);
		buffer[nread] = '\0';
		if (!next_line)
			next_line = ft_strdup("");
		line = next_line;
		next_line = ft_strjoin(line, buffer);
		free(line);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*next_line[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = read_line(fd, buffer, next_line[fd]);
	free(buffer);
	if (!line)
		return (NULL);
	next_line[fd] = extract_next_line(line);
	process_line(line);
	return (line);
}
