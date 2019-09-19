/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 21:45:43 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/15 21:46:16 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

	i = 0;
	while (i < size)
	{
		tetri->next = makelist(str + i, letter);
		tetri = tetri->next;
		letter++;
		i += 21;
	}
	tetri->next = NULL;
	return (tetri);
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
	return (shifter(piece));
}

t_piece	*reader(const int fd)
{
	char	buf[545];
	int		byte_count;
	int		i;
	char	letter;
	t_piece	*tetri;

	i = 0;
	letter = 'A';
	if ((byte_count = read(fd, buf, 546)) < 19 || byte_count > 545)
		return (NULL);
	buf[byte_count] = '\0';
	if (checker(buf, byte_count) > 0)
		return (NULL);
	tetri = makelist(buf, letter);
	addpiece(tetri, buf + 21, byte_count, letter);
	return (tetri);
}
