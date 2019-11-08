/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/30 13:17:30 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solve_map(char **map, t_piece *tetri, int size)
{
	t_pos		pos;
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

int		check_place(char **map, t_piece *piece, t_pos pos, char c)
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

void	insert_piece(char **map, t_piece *piece, t_pos pos, char c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		map[piece->coord[i + 1] + pos.y][piece->coord[i] + pos.x] = c;
		i += 2;
	}
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
	print_map(map, size);
	free_map(map, size);
	free_tetri(tetri);
	free_tetri(piece);
	return (map);
}
