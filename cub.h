#ifndef CUB_H
#define CUB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

typedef struct s_elements
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}	t_elements;

typedef struct s_map
{
	char		**map;
	int		width;
	int		height;
	t_elements	elements;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
	char	dir;
}	t_player;

typedef struct s_flood
{
	char	**copy;
	int		width;
	int		height;
	int		error;
}	t_flood;

int		find_map(char **map, int *i);
int		is_valid_char(char c);

char    **set_map(int fd, char *argv);

void	 print_map(char **map);
void	 free_map(char **map);

int		set_elements(char *line, t_elements *elements);
void	init_elements(t_elements *elements);
void	free_elements(t_elements *elements);
void	parser_error(int fd, char **lines, t_elements *elements, char *message);
int		check_color(char *color);
int		element_seen(char *line, t_elements *elements);
int		parse_file(int argc, char **argv, t_map *map, t_player *player);
int		check_map_chars(char **map_line, t_map *map);
int		find_spawn(char **map_line, t_map map, t_player *player);
int		check_map_closed(char **map_line, t_map *map, t_player *player);

#endif