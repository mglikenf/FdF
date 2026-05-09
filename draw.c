/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:27:34 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 18:00:05 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_iso(t_fdf *fdf)
{
	int	row;
	int	col;

	row = 0;
	while (row < fdf->map.height)
	{
		col = 0;
		while (col < fdf->map.width)
		{
			if (row + 1 < fdf->map.height)
				ft_draw_segment(fdf, &fdf->map.points[row][col], &fdf->map.points[row + 1][col]);
			if (col + 1 < fdf->map.width)
				ft_draw_segment(fdf, &fdf->map.points[row][col], &fdf->map.points[row][col + 1]);
			col++;
		}
		row++;
	}
	mlx_put_image_to_window(fdf->mlx_data.mlx_ptr, fdf->mlx_data.win_ptr, fdf->mlx_data.img_ptr, 0, 0);
}

void ft_draw_segment(t_fdf* fdf, t_point *p1, t_point* p2)
{
	t_line line;

	line.x0 = p1->x_prime * fdf->map.scale + fdf->map.offset_x;
	line.y0 = p1->y_prime * fdf->map.scale + fdf->map.offset_y;
	line.x1 = p2->x_prime * fdf->map.scale + fdf->map.offset_x;
	line.y1 = p2->y_prime * fdf->map.scale + fdf->map.offset_y;
	line.dx = abs(line.x1 - line.x0);
	line.dy = abs(line.y1 - line.y0);
	line.err = line.dx - line.dy;
	ft_calculate_increment(&line);
	ft_draw_line(fdf, line);
}

void	ft_calculate_increment(t_line *line)
{
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
}

void	ft_draw_line(t_fdf *fdf, t_line line)
{
	int	err2;

	while (line.x0 != line.x1 || line.y0 != line.y1)
	{
		if (line.x0 >= 0 && line.y0 >= 0 && line.x0 < WIDTH && line.y0 < HEIGHT)
			put_pixel_to_image(fdf, line.x0, line.y0, 0xFFFFFF);
		err2 = 2 * line.err;
		if (err2 > -line.dy)
		{
			line.err -= line.dy;
			line.x0 += line.sx;
		}
		if (err2 < line.dx)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

void	put_pixel_to_image(t_fdf *fdf, int x, int y, int color)
{
	char	*position;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		position = fdf->mlx_data.img_data + (y * fdf->mlx_data.size_line + x
				* (fdf->mlx_data.bits_per_pixel / 8));
		*(int *)position = color;
	}
}
