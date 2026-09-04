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
			break;
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

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}