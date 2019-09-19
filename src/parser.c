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

t_piece	*shifter(t_piece *tetriptr)
{
	while (tetriptr->coord[0] != 0 && tetriptr->coord[2] != 0 && \
	tetriptr->coord[4] != 0 && tetriptr->coord[2] != 6)
	{
		tetriptr->coord[0] -= 1;
		tetriptr->coord[2] -= 1;
		tetriptr->coord[4] -= 1;
		tetriptr->coord[6] -= 1;
	}
	while (tetriptr->coord[1] != 0 && tetriptr->coord[3] != 0 && \
	tetriptr->coord[5] != 0 && tetriptr->coord[7] != 0)
	{
		tetriptr->coord[1] -= 1;
		tetriptr->coord[3] -= 1;
		tetriptr->coord[5] -= 1;
		tetriptr->coord[7] -= 1;
	}
	return (tetriptr);
}

t_piece	*makepiece(char *str, char letter)
{
	t_piece	*tetriptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tetriptr = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	tetriptr->letter = letter;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			tetriptr->coord[j] = (i >= 5) ? (i % 5) : i;
//			printf("x: %d\n", tetriptr->coord[j]);
			j++;
			tetriptr->coord[j] = i / 5;
//			printf("y: %d\n", tetriptr->coord[j]);
			j++;
		}
		i++;
	}
	return (shifter(tetriptr));
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
			first = makepiece(str + i, letter);
			cur = first;
		}
		else
		{
			cur->next = makepiece(str + i, letter);
			cur = cur->next;
		}
		letter++;
		i += 21;
	}
	cur->next = NULL;
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
