/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 19:53:22 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/27 03:03:43 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		retmsg(char *str)
{
	ft_putendl(str);
	return (1);
}

int		main(int argc, char **argv)
{
	t_piece	*tetri;

	if (argc != 2)
		return (retmsg("Usage: ./fillit [input file]"));
	if (!(tetri = reader(open(argv[1], O_RDONLY))))
		return (retmsg("error"));
	solve(tetri);
	return (0);
}
