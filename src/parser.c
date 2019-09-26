/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:45:43 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/26 20:40:30 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
/*
t_piece	*dimension(t_piece *piece)
{
	int i;
	int xmin;
	int xmax;
	int ymin;
	int ymax;

	i = 0;
	xmin = piece->coord[i];
	ymin = piece->coord[i + 1];
	xmax = xmin;
	ymax = ymin;
	while (i < 6)
	{
		xmin = (xmin < piece->coord[i + 2]) ? xmin : piece->coord[i + 2];
		xmax = (xmax > piece->coord[i + 2]) ? xmax : piece->coord[i + 2];
//		printf("xmin: %d\n", xmin);
//		printf("xmax: %d\n", xmax);
		i++;
		ymin = (ymin < piece->coord[i + 2]) ? ymin : piece->coord[i + 2];
		ymax = (ymax > piece->coord[i + 2]) ? ymax : piece->coord[i + 2];
		i++;
//		printf("ymin: %d\n", ymin);
//		printf("ymax: %d\n", ymax);
	}
	i = 0;
	piece->width = xmax - xmin + 1;
	piece->height = ymax - ymin + 1;
	return (piece);
}
*/

t_piece	*dimension(t_piece *piece)
{
	int i;
	int xmax;
	int ymax;

	i = 0;
	xmax = piece->coord[i];
	ymax = piece->coord[i + 1];
	while (i < 6)
	{
		xmax = (xmax > piece->coord[i + 2]) ? xmax : piece->coord[i + 2];
//		printf("xmax: %d\n", xmax);
		i++;
		ymax = (ymax > piece->coord[i + 2]) ? ymax : piece->coord[i + 2];
		i++;
//		printf("ymax: %d\n", ymax);
	}
	i = 0;
	piece->width = xmax + 1;
	piece->height = ymax + 1;
//	printf("width: %d\n", piece->width);
//	printf("height: %d\n", piece->height);
	return (piece);
}

t_piece	*shifter(t_piece *tetri)
{
	while (tetri->coord[0] != 0 && tetri->coord[2] != 0 && \
	tetri->coord[4] != 0 && tetri->coord[2] != 6)
	{
		tetri->coord[0] -= 1;
		tetri->coord[2] -= 1;
		tetri->coord[4] -= 1;
		tetri->coord[6] -= 1;
	}
	while (tetri->coord[1] != 0 && tetri->coord[3] != 0 && \
	tetri->coord[5] != 0 && tetri->coord[7] != 0)
	{
		tetri->coord[1] -= 1;
		tetri->coord[3] -= 1;
		tetri->coord[5] -= 1;
		tetri->coord[7] -= 1;
	}
	return (tetri);
}

t_piece	*addpiece(t_piece *tetri, char *str, int size, char letter)
{
	int		i;
	t_piece	*first;

	i = 0;
	first = tetri;
	while ((i + 21) < size)
	{
		i += 21;
		letter++;
//		printf("letter: %c\n", tetri->letter);
		tetri->next = makelist(str + i, letter);
		tetri = tetri->next;
	}
	tetri->next = NULL;
	return (first);
}

t_piece	*makelist(char *str, char letter)
{
	t_piece	*piece;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	piece->letter = letter;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			piece->coord[j] = (i >= 5) ? (i % 5) : i;
//			printf("x: %d\n", piece->coord[j]);
			j++;
			piece->coord[j] = i / 5;
//			printf("y: %d\n", piece->coord[j]);
			j++;
		}
		i++;
	}
	shifter(piece);
//	dimension(piece);
//	printf("width: %d\n", piece->width);
//	printf("height: %d\n", piece->height);
//	printf("\n");
	return (dimension(piece));
}

t_piece		*reader(const int fd)
{
	char	buf[545];
	int		byte_count;
	char	letter;
	t_piece	*tetri;

	letter = 'A';
	if ((byte_count = read(fd, buf, 546)) < 19 || byte_count > 545)
		return (NULL);
	buf[byte_count] = '\0';
	if (checker(buf, byte_count) > 0)
		return (NULL);
//	printf("size: %d\n\n", byte_count);
	tetri = makelist(buf, letter);
	tetri = addpiece(tetri, buf, byte_count, letter);
	return (tetri);
}
