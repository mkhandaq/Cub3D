#include "cub.h"

int check_map_chars(char **map_line, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
        {
			if (!is_valid_char(map_line[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_spawn(char **map_line, t_player *player)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while(map_line[i])
	{
        j = 0;
        while (j < map->width)
        {
			if (map_line[i][j] == 'N' || map_line[i][j] == 'S'
				|| map_line[i][j] == 'E' || map_line[i][j] == 'W')
            {
				count++;
				player->y = i;
				player->x = j;
				player->dir = map_line[i][j];
			}
			j++;
		}
		i++;
	}
	return (count == 1);
}
