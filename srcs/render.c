/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:05:33 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/10 04:35:56 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

void	ft_clear(t_img *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 960)
	{
		j = 0;
		while (j < 540)
		{
			my_pixel_put(data, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}
int	render_next_frame(t_img *data)
{
	ft_clear(data);
	sq_put(data, (int)data->x, 27, 0xFFFFFFFF, 10);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	data->x += 0.1;
	return (0);
}
