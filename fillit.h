/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:23:45 by coclayto          #+#    #+#             */
/*   Updated: 2019/11/08 18:08:52 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "libft/includes/libft.h"

typedef struct	s_piece
{
	int				coord[8];
	int				width;
	int				height;
	char			letter;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_pos
{
	int				x;
	int				y;
}				t_pos;

t_piece			*addpiece(t_piece *tetri, char *str, int size, char letter);
t_piece			*makelist(char *str, char letter);
t_piece			*shifter(t_piece *tetri);
t_piece			*reader(const int fd);
t_piece			*dimension(t_piece *tetri);
char			**create_map(int size);
char			**solve(t_piece *tetri);
int				connections(char *str);
int				blocks(char *str);
int				checker(char *str, int size);
int				map_size(int piece_count);
int				solve_map(char **map, t_piece *tetri, int size);
int				check_place(char **map, t_piece *piece, t_pos pos, char c);
void			insert_piece(char **map, t_piece *piece, t_pos pos, char c);
void			print_map(char **map, int size);
void			free_map(char **map, int size);
void			free_tetri(t_piece *tetri);

#endif
