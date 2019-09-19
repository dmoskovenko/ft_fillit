#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "../libft/includes/libft.h"

typedef struct	s_piece
{
	int				coord[8];
	char			letter;
	struct s_piece	*next;
}				t_piece;

int		retmsg(char *str);
t_piece	*reader(const int fd);
int		connections(char *str);
int		blocks(char *str);
int		checker(char *str, int size);
t_piece	*makelist(char *str, int size);
t_piece	*makepiece(char *str, char letter);
t_piece	*shifter(t_piece *tetriptr);

#endif
