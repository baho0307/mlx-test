/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 04:05:33 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/12 22:59:48 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

void	ft_clear(t_img *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->height, data->width);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
}

void	ft_render_map(t_img *data)
{
	char	**map;
	int		i;
	int		j;
	int		map_x;

	map = data->map;
	map_x = data->width * 2 / ft_strlen(map[0]);
	printf("\n%d\n", map_x);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				sq_put(data, j * map_x / 2, i * map_x, 0xFFFFFFFF, map_x);
			}
			j++;
		}
		i++;
	}
}

int	render_next_frame(t_img *data)
{
	ft_clear(data);
	ft_render_map(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}
