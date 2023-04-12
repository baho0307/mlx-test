/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:51:33 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/12 00:13:36 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

void	my_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	sq_put(t_img *data, int x, int y, int color, int size)
{
	int	i;

	i = 0;
	while (i < size * size)
	{
		my_pixel_put(data, (i % size) + x, (i / size) + y, color);
		i++;
	}
}
