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

int		retmsg(char *str)
{
	ft_putendl(str);
	return (1);
}

t_piece	*makepiece(char *str, char letter)
{
	t_piece	*tetriptr;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 1;
	if (!(tetriptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	tetriptr->letter = letter;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			tetriptr->coord[x] = (i >= 5) ? (i % 5) : i;
			tetriptr->coord[y] = i / 5;
			x += 2;
			y += 2;
		}
		i++;
	}
	return (tetriptr);
}

t_piece	*makelist(char *str, int size)
{
	int		i;
	char	letter;
	t_piece	*cur;
	t_piece	*first;

	i = 0;
	letter = 'A';
	while (i < size)
	{
		if (letter == 'A')
		{
			first = makepiece(str, letter);
			cur = first;
		}
		else
		{
			cur->next = makepiece(str, letter);
			cur = cur->next;
		}
		letter++;
		i += 21;
	}
	return (first);
}

t_piece	*reader(const int fd)
{
	char	buf[545];
	int		byte_count;

	if ((byte_count = read(fd, buf, 546)) < 19 || byte_count > 545)
		return (NULL);
	if (checker(buf, byte_count) > 0)
		return (NULL);
	return (makelist(buf, byte_count));
}

int		main(int argc, char **argv)
{
	t_piece	*tetri;

	if (argc != 2)
		return (retmsg("Usage: ./fillit [input file]"));
	if (!(tetri = reader(open(argv[1], O_RDONLY))))
		return (retmsg("error"));
	return (0);
}
