/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 02:35:40 by coclayto          #+#    #+#             */
/*   Updated: 2019/11/08 18:10:40 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connections(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (str[i] != '#' && i < 20)
			i++;
		if (str[i] == '#')
		{
			if (i % 5 != 0 && str[i - 1] == '#')
				count++;
			if (str[i + 1] == '#')
				count++;
			if (i > 4 && str[i - 5] == '#')
				count++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				count++;
			i++;
		}
	}
	return (count);
}

int		blocks(char *str)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		while ((i % 5) < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (1);
			if (str[i] == '#' && ++block > 4)
				return (2);
			i++;
		}
		if (str[i] == '\n')
			i++;
		else
			return (3);
	}
	return (0);
}

int		checker(char *str, int size)
{
	int i;

	i = 0;
	if (str[size - 1] == '\n' && str[size - 2] == '\n')
		return (1);
	while (i < size)
	{
		if (blocks(str + i))
			return (1);
		if (!(connections(str + i) == 6 || connections(str + i) == 8))
			return (1);
		i += 21;
	}
	return (0);
}
