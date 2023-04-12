/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:38:46 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/12 22:36:45 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

int	main(int argc, char *argv[])
{
	t_img	img;

	img.mlx = mlx_init();
	img.map = read_file(argv[argc - 1]);
	img.height = 800;
    img.width = 800;
	img.img = mlx_new_image(img.mlx, img.height, img.width);
	img.mlx_win = mlx_new_window(img.mlx, 800, 800, "TEST");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
	free(img.mlx);
	free(img.img);
	free(img.map);
	free(img.mlx_win);
	return (0);
}
