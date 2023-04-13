/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 02:36:46 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/13 02:25:45 by bahadir yig      ###   ########.fr       */
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
	if (fd != -1 && ft_strcmp(ft_strstr(filename, "."), "bhdr"))
	{
		i = 0;
		j = 0;
		while (read(fd, &c, 1))
		{
			if (c == '\n')
			{
				j++;
				i = 0;
			}
			else if (c == '1' || c == '0')
			{
				ret[j][i] = c;
				i++;
			}
		}
	}
	else
	{
		printf("Wrong filename\n");
		return (NULL);
	}
	close(fd);
	return (ret);
}
