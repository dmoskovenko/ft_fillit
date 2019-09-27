/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/27 20:12:39 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(char **map, t_piece *tetri, int size)
{
	t_position	pos;
	t_piece		*piece;

	if (tetri == NULL)
		return (1);
	pos.y = 0;
	piece = tetri;
	while (pos.y < size - piece->height + 1)
	{
		pos.x = 0;
		while (pos.x < size - piece->width + 1)
		{
			if (check_place(map, piece, pos, piece->letter))
			{
				if (solve_map(map, piece->next, size))
					return (1);
				else
					insert_piece(map, piece, pos, '.');
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

void	print_map(char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			write(1, &(map[y][x]), 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}

int		check_place(char **map, t_piece *piece, t_position pos, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (map[piece->coord[i + 1] + pos.y][piece->coord[i] + pos.x] != '.')
			return (0);
		i += 2;
	}
	insert_piece(map, piece, pos, c);
	return (1);
}

void	insert_piece(char **map, t_piece *piece, t_position pos, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		map[piece->coord[i + 1] + pos.y][piece->coord[i] + pos.x] = c;
		i += 2;
	}
}

int		map_size(int piece_count)
{
	int size;

	size = 2;
	while (size * size < (piece_count * 4))
		size++;
	return (size);
}

char		**create_map(int size)
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

void	free_tetri(t_piece *tetri)
{
	t_piece		*piece;

	while (tetri)
	{
		piece = tetri;
		tetri = piece->next;
		free(piece);
	}
}

char	**solve(t_piece *tetri)
{
	t_piece	*piece;
	char	**map;
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
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	print_map(map);
	free_map(map, size);
	free_tetri(tetri);
	return (map);
}