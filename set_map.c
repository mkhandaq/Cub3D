#include "cub.h"

int lines_count(int fd)
{
	char *line;
	int count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count ++;
		free(line);
		line = get_next_line(fd);
	}
	return (count);
}

char    **set_map(int fd)
{
    char	**map;
	int		lines;
	int		i;

	lines = lines_count(fd);
    map = malloc(lines + 1);
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
	return (map);
}
