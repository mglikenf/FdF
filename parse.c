/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:18:29 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 21:54:07 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_map(t_fdf *fdf, char *file_name)
{
	int		fd;
	int		j;
	char	*line;

	fdf->map.width = -1;
	j = 0;
	fd = open_file(file_name, fdf);
	line = get_next_line(fd);
	if (!line)
		ft_cleanup_exit(fdf, line, "Map is not valid\n");
	while (line)
	{
		ft_map_width(fdf, line, &fdf->map.width, fd);
		j++;
		line = get_next_line(fd);
	}
	close(fd);
	fdf->map.height = j;
}

void	ft_map_width(t_fdf *fdf, char *line, int *width, int fd)
{
	char	**values;
	int		i;

	values = ft_split(line, ' ');
	if (!values)
		return (ft_cleanup_exit(fdf, line, "Failed to split row\n"));
	i = 0;
	while (values[i])
		i++;
	if (*width == -1)
		*width = i;
	else if (*width != i)
	{
		purge_gnl(fd);
		ft_free_array(values);
		ft_cleanup_exit(fdf, line, "Map is not valid\n");
	}
	free(line);
	ft_free_array(values);
}

void	ft_get_points(t_fdf *fdf, char *map_file)
{
	int	i;
	int	fd;

	fdf->map.points = malloc(sizeof(t_point *) * fdf->map.height);
	if (!fdf->map.points)
		ft_cleanup_exit(fdf, NULL, "Malloc error for points array\n");
	i = 0;
	while (i < fdf->map.height)
	{
		fdf->map.points[i] = malloc(sizeof(t_point) * fdf->map.width);
		if (!fdf->map.points[i])
		{
			while (i > 0)
        		free(fdf->map.points[--i]);
			free(fdf->map.points);
			ft_cleanup_exit(fdf, NULL, "malloc error for points in a row\n");
		}
		i++;
	}
	fd = open_file(map_file, fdf);
	ft_fill_map(fdf, fd);
	close(fd);
}

void	ft_fill_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		row;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_fill_row(fdf, line, row);
		free(line);
		row++;
		line = get_next_line(fd);
	}
}

void	ft_fill_row(t_fdf *fdf, char *line, int row)
{
	char	**values;
	int		col;

	col = 0;
	values = ft_split(line, ' ');
	if (!values)
		return (ft_cleanup_exit(fdf, line, "Failed to split row\n"));
	while (col < fdf->map.width)
	{
		fdf->map.points[row][col].x = col;
		fdf->map.points[row][col].y = row;
		fdf->map.points[row][col].z = ft_atoi(values[col]);
		col++;
	}
	ft_free_array(values);
}
