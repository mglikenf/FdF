/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:45:53 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 15:32:49 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_init_mlx(t_fdf *fdf)
{
	fdf->mlx_data.mlx_ptr = mlx_init();
	if (!fdf->mlx_data.mlx_ptr)
		return (ft_putstr_fd("failed to set up connection to mlx", 2), 0);
	fdf->mlx_data.win_ptr = mlx_new_window(fdf->mlx_data.mlx_ptr, WIDTH, HEIGHT,
			"New Window");
	if (!fdf->mlx_data.win_ptr)
	{
		mlx_destroy_display(fdf->mlx_data.mlx_ptr);
		return (ft_putstr_fd("failed to create a new window", 2), 0);
	}
	fdf->mlx_data.img_ptr = mlx_new_image(fdf->mlx_data.mlx_ptr, WIDTH, HEIGHT);
	if (!fdf->mlx_data.img_ptr)
	{
		mlx_destroy_window(fdf->mlx_data.mlx_ptr, fdf->mlx_data.win_ptr);
		mlx_destroy_display(fdf->mlx_data.mlx_ptr);
		return (ft_putstr_fd("failed to create a new image", 2), 0);
	}
	fdf->mlx_data.img_data = mlx_get_data_addr(fdf->mlx_data.img_ptr,
			&fdf->mlx_data.bits_per_pixel, &fdf->mlx_data.size_line,
			&fdf->mlx_data.endian);
	return (1);
}

void	ft_exit_mlx(t_fdf *fdf)
{
	ft_clear_map(&fdf->map);
	mlx_destroy_window(fdf->mlx_data.mlx_ptr, fdf->mlx_data.win_ptr);
	mlx_destroy_image(fdf->mlx_data.mlx_ptr, fdf->mlx_data.img_ptr);
	mlx_destroy_display(fdf->mlx_data.mlx_ptr);
	free(fdf->mlx_data.mlx_ptr);
}

int	handle_key_input(int keysym, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keysym == XK_Escape)
	{
		ft_exit_mlx(fdf);
		exit(0);
	}
	return (0);
}

int	ft_close_window(t_fdf *fdf)
{
	ft_exit_mlx(fdf);
	exit(0);
	return (0);
}
