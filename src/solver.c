/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/21 21:52:03 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**create_map(t_piece *tetri)
{
	char	**map;
	int		piece_count;
	int		i;
	
	i = 0;
	piece_count = 0;
	while (tetri)
	{
		printf("piece_count: %d\n", piece_count);
		printf("x: %d\n", tetri->coord[0]);
		printf("y: %d\n", tetri->coord[1]);
		printf("x: %d\n", tetri->coord[2]);
		printf("y: %d\n", tetri->coord[3]);
		printf("x: %d\n", tetri->coord[4]);
		printf("y: %d\n", tetri->coord[5]);
		printf("x: %d\n", tetri->coord[6]);
		printf("y: %d\n", tetri->coord[7]);
		tetri = tetri->next;
		piece_count++;
	}
	map = (char**)malloc(sizeof(*map) * piece_count);
/*
	while (i < piece_count)
	{
		map[i] = (char*)malloc(sizeof(map) * piece_count + 1);
		ft_memset(map[i], '.', piece_count);
		map[i][piece_count + 1] = '\0';
		printf("map\n%s\n", map[i]);
	}
*/
	return (map);
}

/*
t_piece		solver(t_piece *tetri)
{
	char	**map;


}
*/