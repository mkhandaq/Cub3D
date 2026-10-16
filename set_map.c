#include "cub.h"

static int lines_count(char *argv)
{
	char *line;
	int count;
	int	fd;

	fd = open (argv, O_RDONLY);
	if (fd == -1)
		return 0;
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count ++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (count);
}

static void trim_cr(char *line)
{
	int	length;

	length = ft_strlen(line);
	if (length > 0 && line[length - 1] == '\r')
		line[length - 1] = '\0';
}

char	**set_map(int fd, char *argv)
{
	char	**map;
	int		lines;
	int		i;

	lines = lines_count(argv);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		trim_cr(map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void print_map(char **map)
{
	int	i;

	i = 0;
	while(map && map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

void	 free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

#include "cub.h"

// static void	map_frame(char **map_line, t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	map->width = 0;
// 	while (map_line[i])
// 		i++;
// 	map->height = i;
// 	i = 0;
// 	while (map_line[i])
// 	{
// 		j = 0;
// 		while (map_line[i][j])
// 			j++;
// 		if (j > map->width)
// 			map->width = j;
// 		i++;
// 	}
// }

// void	padding(t_map *map)
// {
// 	int		i;
// 	int		j;
// 	int		space;
// 	char	**map_line;
// 	char	*tmp;

// 	if (!find_map(map->map, &i))
// 	{
// 		printf("Error while finding map\n");
// 		return ;
// 	}
// 	map_line = map->map + i;
// 	i = 0;
// 	map_frame(map_line, map);
// 	while (map_line[i])
// 	{
// 		tmp = malloc(ft_strlen(map_line[i]) + 1);
// 		if (!tmp)
// 			return ;
// 		ft_memcpy(tmp, map_line[i], ft_strlen(map_line[i]));
// 		free(map_line[i]);
// 		map_line[i] = malloc(map->width + 1);
// 		if (!map_line[i])
// 		{
// 			free(tmp);
// 			return ;
// 		}
// 		space = map->width - ft_strlen(tmp);
// 		j = 0;
// 		while (j < space)
// 		{
// 			map_line[i][j] = ' ';
// 			j++;
// 		}
// 		ft_memcpy(map_line[i] + space, tmp, ft_strlen(tmp));
// 		map_line[i][map->width] = '\0';
// 		free(tmp);
// 		i++;
// 	}
// }
