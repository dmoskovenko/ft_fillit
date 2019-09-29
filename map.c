/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:16:31 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/29 18:58:32 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		map_size(int piece_count)
{
	int size;

	size = 2;
	while (size * size < (piece_count * 4))
		size++;
	return (size);
}

char	**create_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	map = (char**)ft_memalloc(sizeof(map) * size + 1);
	while (i < size)
	{
		map[i] = ft_strnew(size);
		ft_memset(map[i], '.', size);
		i++;
	}
	return (map);
}

void	free_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < size)
	{
		while (x < size)
		{
			write(1, &(map[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}
