/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:33:58 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/23 02:03:33 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**insert_piece(char **map, t_piece *tetri)
{
	int		x;
	int		y;

	x = 0;
	y = 1;
	while (x <= 7 && y <= 9)
	{
		map[tetri->coord[y]][tetri->coord[x]] = tetri->letter;
		x += 2;
		y += 2;
	}
	return (map);
}

char		**create_map(t_piece *tetri)
{
	t_piece	*piece;
	char	**map;
	int		piece_count;
	int		i;
	
	piece = tetri;
	i = 0;
	piece_count = 0;
	while (tetri)
	{
/*		printf("piece#%d\n", piece_count + 1);
		printf("letter: %c\n", tetri->letter);
		printf("x1: %d\t", tetri->coord[0]);
		printf("y1: %d\n", tetri->coord[1]);
		printf("x2: %d\t", tetri->coord[2]);
		printf("y2: %d\n", tetri->coord[3]);
		printf("x3: %d\t", tetri->coord[4]);
		printf("y3: %d\n", tetri->coord[5]);
		printf("x4: %d\t", tetri->coord[6]);
		printf("y5: %d\n", tetri->coord[7]);
		printf("\n");
*/
		tetri = tetri->next;
		piece_count++;
	}
//	printf("\n");
	map = (char**)malloc(sizeof(*map) * 4 + 1);
	while (i < 4)
	{
		map[i] = (char*)malloc(sizeof(map) * 4 + 1);
		ft_memset(map[i], '.', 4);
		map[i][4 + 1] = '\0';
		i++;
	}
	map[i] = NULL;
	map = insert_piece(map, piece);
	i = 0;
	while(i < 4)
	{
		printf("%s\n", map[i]);
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