/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:49:13 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/10 19:25:18 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_input(int argc, char **argv)
{
	char	*s;
	int		fd;

	if (argc != 2)
		return (ft_putstr_fd("Invalid number of arguments\n", 2), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("File does not exist\n", 2), 0);
	close(fd);
	s = ft_strchr(argv[1], '.');
	if (s && ft_strlen(s) == 4 && ft_strnstr(s, ".fdf", ft_strlen(s)))
		return (1);
	return (ft_putstr_fd("Wrong file extension\n", 2), 0);
}

int	open_file(char *file_name, t_fdf *fdf)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_cleanup_exit(fdf, NULL, "Error opening file\n");
	return (fd);
}

void	ft_cleanup_exit(t_fdf* fdf, char *line, char *msg)
{
	if (line)
		free(line);
	ft_exit_mlx(fdf);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	purge_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}