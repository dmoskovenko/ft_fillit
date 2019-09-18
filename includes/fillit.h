#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "../libft/includes/libft.h"

int		connections(char *str);
int		blocks(char *str);
int		checker(char *str, int size);

typedef struct	s_piece
{
	int				coord[8];
	char			letter;
	struct s_piece	*next;
}				t_piece;

#endif
