/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:23:45 by coclayto          #+#    #+#             */
/*   Updated: 2019/09/26 23:44:45 by coclayto         ###   ########.fr       */
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
	int				width;
	int				height;
	char			letter;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_map
{
	int			size;
	char		**arr;
}				t_map;

int				connections(char *str);
int				blocks(char *str);
int				checker(char *str, int size);
int				map_size(int piece_count);
int				solve_map(t_map *map, t_piece *tetri, int size);
void			print_map(t_map *map);
t_map			*create_map(int size);
void			insert_piece(t_map *map, t_piece *tetri, int x, int y, char c);
int				check_place(t_map *map, t_piece *piece, int x, int y, char c);
t_piece			*addpiece(t_piece *tetri, char *str, int size, char letter);
t_piece			*makelist(char *str, char letter);
t_piece			*shifter(t_piece *tetri);
t_piece			*reader(const int fd);
t_piece			*dimension(t_piece *tetri);
//void			set_piece(t_piece *tetri, t_map *map, int x, int y, char c);
t_map			*solve(t_piece *tetri);
void			free_map(t_map *map, int size);

#endif
