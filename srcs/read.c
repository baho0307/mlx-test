/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:36:46 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/12 22:37:02 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

char	**read_file(char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	c;
	char	**ret;

	ret = ft_filealloc(filename);
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		i = 0;
		j = 0;
		while (read(fd, &c, 1))
		{
			ret[j][i] = c;
			if (c == '\n')
			{
				j++;
				i = 0;
			}
			else
				i++;
		}
	}
	close(fd);
	i = 0;
	while (ret[i])
	{
		printf("%s", ret[i]);
		i++;
	}
	return (ret);
}
