/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/27 00:12:14 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		solve_map(t_map *map, t_piece *tetri, int size)
{
	int			x;
	int			y;
	t_piece		*piece;

	if (tetri == NULL)
		return (1);
	y = 0;
	piece = tetri;
//	printf("width: %d\n", piece->width);
//	printf("height: %d\n", piece->height);
	while (y < size - piece->height + 1)
	{
//		printf("y: %d\n", y);
		x = 0;
		while (x < size - piece->width + 1)
		{
//			printf("size: %d\n", size);
//			printf("x: %d\n", x);
			if (check_place(map, piece, x, y, piece->letter))
			{
				if (solve_map(map, piece->next, size))
					return (1);
				else
					insert_piece(map, piece, x, y, '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	print_map(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
		while(map->arr[y])
		{
			while(map->arr[y][x])
			{
				write(1, (void*)&(map->arr[y][x]), 1);
				x++;
			}
//			printf("here\n");
			write(1, "\n", 1);
			x = 0;
			y++;
		}
}

int		check_place(t_map *map, t_piece *piece, int x, int y, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (map->arr[piece->coord[i + 1] + y][piece->coord[i] + x] != '.')
			return (0);
		i += 2;
	}
	insert_piece(map, piece, x, y, c);
	return(1);
}

void	insert_piece(t_map *map, t_piece *piece, int x, int y, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		map->arr[piece->coord[i + 1] + y][piece->coord[i] + x] = c;
//		printf("arr[x]: %d\n", (piece->coord[i] + x));
//		printf("arr[y]: %d\n", (piece->coord[i + 1] + y));
//		printf("s[%d]: %s\n", i, map->arr[piece->coord[i + 1] + y]);
		i += 2;
	}
//	printf("\n");
//	printf("here\n");
}
/*
void	set_piece(t_piece *tetri, t_map *map, int x, int y, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->coord[j][i] == '#')
				map->arr[y + j][x + i] = c;
			j++;
		}
		i++;
	}
//	ft_memdel((void **)&point);
}
*/

int		map_size(int piece_count)
{
	int size;

	size = 2;
	while (size * size < (piece_count * 4))
		size++;
	return (size);
}

t_map		*create_map(int size)
{
//	t_piece	*piece;
	t_map	*map;
	int		i;
	
	i = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->arr = (char**)ft_memalloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map->arr[i] = ft_strnew(size);
		ft_memset(map->arr[i], '.', size);
		i++;
	}
	return (map);
}

void	free_map(t_map *map, int size)
{
	int i;

	i = 0;
	while (i < size)
// 	printf("size: %d\n", size);
	{
		ft_memdel((void **)&(map->arr[i]));
		i++;
	}
	ft_memdel((void **)&(map->arr));
	ft_memdel((void **)&map);
}

t_map	*solve(t_piece *tetri)
{
	t_piece	*piece;
	t_map	*map;
	int		size;
	int		piece_count;

	piece = tetri;
	piece_count = 0;
	while (tetri)
	{
		tetri = tetri->next;
		piece_count++;
	}
	size = map_size(piece_count);
	map = create_map(size);
	while (!solve_map(map, piece, size))
	{
//		printf("size: %d\n", size);
//		print_map(map);
//		printf("\n");
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	print_map(map);
	return (map);
}