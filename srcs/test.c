/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:38:46 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/10 04:28:13 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

int	main(void)
{
	t_img	img;

	img.mlx = mlx_init();
	img.img = mlx_new_image(img.mlx, 960, 540);
	img.x = 0;
	img.mlx_win = mlx_new_window(img.mlx, 960, 540, "TEST");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
}
