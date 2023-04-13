/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:05:33 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/13 15:17:03 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

void	ft_clear(t_img *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->width * data->zoom, data->height * data->zoom);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	data->y += .01;
	data->x += .01;
}

void	ft_render_map(t_img *data)
{
	int		i;
	int		j;
	int		map_x;
	int		map_y;

	map_x = data->width * data->zoom / ft_strlen(data->map[0]);
	map_y = data->height * data->zoom / ft_strstrlen(data->map);
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				sq_put(data, j * map_x , i * map_y, 0xFFFFFFFF, map_x);
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_img *data)
{
	ft_clear(data);
	ft_render_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, data->x, data->y);
	return (0);
}
