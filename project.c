/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:29:01 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 16:30:51 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_project(t_fdf *fdf)
{
	int		row;
	int		col;
	float	cos_angle;
	float	sin_angle;

	row = 0;
	cos_angle = cos(M_PI / 6);
	sin_angle = sin(M_PI / 6);
	while (row < fdf->map.height)
	{
		col = 0;
		while (col < fdf->map.width)
		{
			fdf->map.points[row][col].x_prime = (fdf->map.points[row][col].x
					- fdf->map.points[row][col].y) * cos_angle;
			fdf->map.points[row][col].y_prime = (fdf->map.points[row][col].x
					+ fdf->map.points[row][col].y) * sin_angle
				- fdf->map.points[row][col].z;
			col++;
		}
		row++;
	}
}

void	ft_minmax(t_map *map, t_point **points, int height, int width)
{
	int	i;
	int	j;

	map->x_min = points[0][0].x_prime;
	map->y_min = points[0][0].y_prime;
	map->x_max = points[0][0].x_prime;
	map->y_max = points[0][0].y_prime;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (points[i][j].x_prime < map->x_min)
				map->x_min = points[i][j].x_prime;
			if (points[i][j].y_prime < map->y_min)
				map->y_min = points[i][j].y_prime;
			if (points[i][j].x_prime > map->x_max)
				map->x_max = points[i][j].x_prime;
			if (points[i][j].y_prime > map->y_max)
				map->y_max = points[i][j].y_prime;
			j++;
		}
		i++;
	}
}

void	ft_scale_offset(t_map *map)
{
	float	obj_width;
	float	obj_height;
	float	obj_center_x;
	float	obj_center_y;

	obj_width = map->x_max - map->x_min;
	obj_height = map->y_max - map->y_min;
	map->scale = fmin((WIDTH - 16) / obj_width, (HEIGHT - 9) / obj_height);
	obj_center_x = map->scale * obj_width / 2;
	obj_center_y = map->scale * obj_height / 2;
	map->offset_x = WIDTH / 2 - (map->x_min * map->scale + obj_center_x);
	map->offset_y = HEIGHT / 2 - (map->y_min * map->scale + obj_center_y);
}
