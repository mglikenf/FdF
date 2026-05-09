/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:38:11 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 21:24:48 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

# define WIDTH 1280
# define HEIGHT 720

# ifndef M_PI
# define M_PI 3.14159265358979323846
# endif

# include "libft/get_next_line/get_next_line_bonus.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_line
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}				t_line;

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	float	x_prime;
	float	y_prime;
}			t_point;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**points;
	float	x_min;
	float	x_max;
	float	y_min;
	float	y_max;
	float	scale;
	float	offset_x;
	float	offset_y;
}			t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		size_line;
	int		bits_per_pixel;
	int		endian;

}			t_mlx;

typedef struct s_fdf
{
	t_mlx	mlx_data;
	t_map	map;
}			t_fdf;

int			ft_check_input(int argc, char **argv);
int			ft_init_mlx(t_fdf *fdf);
void		ft_parse_map(t_fdf *fdf, char *file_name);
int			open_file(char *file_name, t_fdf *fdf);
void		ft_map_width(t_fdf *fdf, char *line, int *width, int fd);
void		ft_get_points(t_fdf *fdf, char *map_file);
void		ft_fill_map(t_fdf *fdf, int fd);
void		ft_fill_row(t_fdf *fdf, char *line, int row);
void		ft_project(t_fdf *fdf);
void		ft_minmax(t_map *map, t_point **points, int height, int width);
void		ft_scale_offset(t_map *map);
void		ft_clear_map(t_map *map);
void		ft_exit_mlx(t_fdf *fdf);
void		purge_gnl(int fd);
int			ft_close_window(t_fdf *fdf);
void		ft_free_array(char **array);
void		ft_draw_iso(t_fdf *fdf);
void		ft_draw_segment(t_fdf* fdf, t_point *p1, t_point* p2);
void		ft_calculate_increment(t_line *line);
void		ft_draw_line(t_fdf *fdf, t_line line);
void		put_pixel_to_image(t_fdf *fdf, int x, int y, int color);
int			handle_key_input(int keysym, void *param);
void		ft_cleanup_exit(t_fdf* fdf, char *line, char *msg);

#endif
