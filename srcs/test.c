/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:38:46 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/13 20:57:49 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

t_img	create_image(char *filename, float x, float y)
{
	t_img	img;

	img.mlx = mlx_init();
	img.map = read_file(filename);
	img.width = ft_strlen(img.map[0]) * 30;
	img.height = ft_strstrlen(img.map) * 30;
	img.zoom = 1;
	img.x = x;
	img.y = y;
	img.img = mlx_new_image(img.mlx, img.width, img.height);
	img.mlx_win = mlx_new_window(img.mlx, 960, 540, "TEST");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	return (img);
}

int	main(int argc, char *argv[])
{
	t_img	img;

	img = create_image(argv[argc - 1], 0, 0);
	printf("%d\n", img.width);
	printf("%d\n", img.height);
	if (img.map)
	{
		mlx_loop_hook(img.mlx, render_next_frame, &img);
		mlx_loop(img.mlx);
		free(img.img);
		free(img.mlx);
		free(img.map);
		free(img.mlx_win);
	}
	return (0);
}
