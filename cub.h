#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int	width;
	int	height;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	char dir;
}	t_player;

int		find_map(char **map, int *i);

char    **set_map(int fd, char *argv);

void	 print_map(char **map);
void	 free_map(char **map);

#endif