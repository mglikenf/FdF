/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:49:03 by mglikenf          #+#    #+#             */
/*   Updated: 2024/10/09 21:27:26 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_memset(&fdf, 0, sizeof(t_fdf));
	if (!ft_check_input(argc, argv) || ! ft_init_mlx(&fdf))
		exit(1);
	ft_parse_map(&fdf, argv[1]);
	ft_get_points(&fdf, argv[1]);
	ft_project(&fdf);
	ft_minmax(&fdf.map, fdf.map.points, fdf.map.height, fdf.map.width);
	ft_scale_offset(&fdf.map);
	ft_draw_iso(&fdf);
	mlx_key_hook(fdf.mlx_data.win_ptr, &handle_key_input, &fdf);
	mlx_hook(fdf.mlx_data.win_ptr, 17, 0, ft_close_window, &fdf);
	mlx_loop(fdf.mlx_data.mlx_ptr);

	return (0);
}
