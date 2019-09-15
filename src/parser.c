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

#include <fcntl.h>
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "../includes/fillit.h"

int		retmsg(char *str)
{
	ft_putendl(str);
	return (1);
}

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
			if (i > 5 && str[i - 5] == '#')
				count++;
			if (i < 20 && str[i + 5] == '#')
				count++;
			i++;
		}
	}
	return (count);
}

int		checker(char *str, int byte_count)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	while (i < 20)
	{
		while (i % 5 < 4)
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
			return (2);
	}
	if (byte_count == 21 && str[20] != '\n')
		return (4);
	if (connections(str) != 6 && connections(str) != 8)
		return (5);
	return (0);
}

int		reader(const int fd)
{
	char	buf[21];
	int		byte_count;
	int		tetri_count;

	tetri_count = 0;
	while ((byte_count = read(fd, buf, 21)) >= 20)
	{
		printf("Tetri#%d\n", tetri_count + 1);
		printf("%s\n", buf);
		if (checker(buf, byte_count) > 0)
		{
			printf("\nchecker return: %d\n", checker(buf, byte_count));
			return (1);
		}
		tetri_count++;
		if (tetri_count > 26)
			return (1);
	}
	if (byte_count == 0 && tetri_count == 0)
		return (1);
	if (byte_count == 0)
		return (0);
	else
		return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (retmsg("Usage: ./fillit [input file]"));
	if (reader(open(argv[1], O_RDONLY)) == 1)
		return (retmsg("error"));
	return (0);
}
