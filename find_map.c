#include "cub.h"

int is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' ||
			c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int is_map_line(char *line)
{
    int i;

    if (!line || !line[0])
        return (0);
    i = 0;
    while (line[i] && line[i] != '\0')
    {
        if (!is_valid_char(line[i]))
            return (0);
        i++;
    }
    return (1);
}

int	find_map(char **map, int *i)
{
	int	j;

	*i = 0;
	while (map && map[*i])
	{
		if (is_map_line(map[*i]))
			break ;
		(*i)++;
	}
	if(!map || !map[*i])
		return (0);
	j = *i;
	while (map && map[j])
	{
		if (!is_map_line(map[j]))
			return (0);
		j++;
	}
	return (1);
}

