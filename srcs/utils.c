/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahadir yigit <bahadiryigit0307@gmail.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:30:50 by bahadir yig       #+#    #+#             */
/*   Updated: 2023/04/13 02:14:08 by bahadir yig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_test.h"

int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (!('0' <= str[i] && str[i] <= '9') && str[i])
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	return (r);
}

int	ft_strcmp(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while ((str1[i] == str2[i]) && str1[i])
		i++;
	return (str1[i] - str2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (!to_find[i])
		return (str);
	while (str[i])
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && str[i + j])
		{
			j++;
			if (!to_find[j])
				return (str + i);
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_filealloc(char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	c;
	char	**ret;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	i = 0;
	j = 0;
	while (read(fd, &c, 1))
	{
		if (!j && c != '\n' && c != ' ')
			i++;
		else if (c == '\n')
			j++;
	}
	c = 0;
	ret = (char **) malloc(sizeof(char *) * (j + 1));
	while (c < j)
		ret[(int)c++] = (char *) malloc(sizeof(char) * (i + 1));
	close(fd);
	return (ret);
}
