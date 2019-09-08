#include <fcntl.h>
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
//#include "fillit.h"

int		retmsg(char* str)
{
	ft_putendl(str);
	return(1);
}

int		checker(char* str)
{
	int		i;
	int		block;

	i = 0;
	block = 0;
	if(str[i] == '.' || str[i] == '#')
		i++;
	while(i < 20)
	{
		while(i % 5 < 4)
		{
			if(str[i] == '.' || str[i] == '#')
				i++;
			else
				return(1);
		}
		if(str[i] == '\n')
			++block;
		i++;
	}
	if(str[i] == '\n' || str[i] == '\0')
		return(0);
	else
		return(1);
}

int		reader(const int fd)
{
	char	buf[21];
	int		count;

	while((count = read(fd, buf, 21)) >= 20)
	{
		printf("%s\n", buf);
		if(checker(buf) == 1)
			return(1);
	}
	if(count == 0)
		return(0);
	else
		return(1);
}

int		main(int argc, char** argv)
{
	int		size;

	if(argc != 2)
		return(retmsg("Usage: ./fillit [input file]"));
	if(reader(open(argv[1], O_RDONLY)) == 1)
		return(retmsg("error"));
	return(0);
}
