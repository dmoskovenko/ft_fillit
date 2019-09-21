/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/22 00:32:31 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**create_map(t_piece *tetri)
{
	t_piece *piece;
	char	**map;
	int		piece_count;
	int		i;
	
	i = 0;
	piece_count = 0;
	piece = tetri;
	while (piece)
	{
/*
		printf("\npiece#%d\n", piece_count + 1);
		printf("letter: %c\n", tetri->letter);
		printf("x: %d\n", tetri->coord[0]);
		printf("y: %d\n", tetri->coord[1]);
		printf("x: %d\n", tetri->coord[2]);
		printf("y: %d\n", tetri->coord[3]);
		printf("x: %d\n", tetri->coord[4]);
		printf("y: %d\n", tetri->coord[5]);
		printf("x: %d\n", tetri->coord[6]);
		printf("y: %d\n", tetri->coord[7]);
*/
		piece = piece->next;
		piece_count++;
	}
	map = (char**)malloc(sizeof(*map) * piece_count);
	while (i < piece_count)
	{
		map[i] = (char*)malloc(sizeof(map) * piece_count + 1);
		ft_memset(map[i], '.', piece_count);
		map[i][piece_count + 1] = '\0';
		printf("map[%d]\n%s\n", i, map[i]);
		i++;
	}
	return (map);
}

/*
t_piece		solver(t_piece *tetri)
{
	char	**map;


}
*/