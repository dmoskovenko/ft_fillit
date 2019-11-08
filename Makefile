NAME = fillit
SRCS = main.c parser.c checker.c solver.c map.c
OBJS = main.o parser.o checker.o solver.o map.o
HDR = fillit.h 
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)
	
$(NAME):
	make -C $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $(SRCS) -I -L. libft/libft.a

clean: 
	/bin/rm -f $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all