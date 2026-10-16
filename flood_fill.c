#include "cub.h"

static char	**alocation(char **map_line)
{
	char	**copy;
	int		argc;
	int		i;

	i = 0;
	while (map_line[i])
		i++;
	argc = i + 1;
	copy = malloc((argc) * (sizeof(char *)));
	if (!copy)
		return (NULL);
	return (copy);
}

static char	**hard_copy(char **map_line)
{
	char	**copy;
	int		i;

	i = 0;
	copy = alocation(map_line);
	if (!copy)
		return (NULL);
	while (map_line[i])
	{
		copy[i] = ft_strdup(map_line[i]);
		if (!copy[i])
		{
			copy[i] = NULL;
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(t_flood *f, int i, int j)
{
	if (i < 0 || j < 0 || j >= f->width || i >= f->height)
	{
		f->error = 1;
		return ;
	}
	if (j >= (int)ft_strlen(f->copy[i]))
	{
		f->error = 1;
		return ;
	}
	if (f->copy[i][j] == '1' || f->copy[i][j] == 'V')
		return ;
	if (f->copy[i][j] == ' ')
	{
		f->error = 1;
		return ;
	}
	f->copy[i][j] = 'V';
	flood_fill(f, i + 1, j);
	flood_fill(f, i - 1, j);
	flood_fill(f, i, j + 1);
	flood_fill(f, i, j - 1);
}

int	check_map_closed(char **map_line, t_map *map, t_player *player)
{
	t_flood	f;

	f.copy = hard_copy(map_line);
	if (!f.copy)
		return (0);
	f.width = map->width;
	f.height = map->height;
	f.error = 0;
	flood_fill(&f, player->y, player->x);
	free_map(f.copy);
	return (f.error == 0);
}