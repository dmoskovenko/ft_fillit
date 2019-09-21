/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:23:45 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/21 20:47:04 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

typedef struct	s_piece
{
	int				coord[8];
	char			letter;
	struct s_piece	*next;
}				t_piece;

int				connections(char *str);
int				blocks(char *str);
int				checker(char *str, int size);
t_piece			*addpiece(t_piece *tetri, char *str, int size, char letter);
t_piece			*makelist(char *str, char letter);
t_piece			*shifter(t_piece *tetri);
t_piece			*reader(const int fd);
char			**create_map(t_piece *tetri);

#endif
