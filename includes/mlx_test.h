/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:15:32 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/12 22:39:36 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_TEST_H
#define MLX_TEST_H
#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	**map;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_img;

void	my_pixel_put(t_img *data, int x, int y, int color);
void	sq_put(t_img *data, int x, int y, int color, int size);
int		render_next_frame(t_img *data);
void	ft_clear(t_img *data);
int		ft_atoi(char *str);
char	**read_file(char *filename);
char	**ft_filealloc(char *filename);
int		ft_strlen(char *str);
void	ft_render_map(t_img *data);

#endif
