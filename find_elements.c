#include "cub.h"

static int texture_open(char *value)
{
	int	fd;
	char	buffer[1];

	fd = open(value, O_RDONLY);
	if (fd == -1)
		return (0);
	if (read(fd, buffer, 1) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

char	*get_line_value(char *line)
{
	int		i;
	char	*value;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	value = ft_strdup(line + i);
	return (value);
}

int	set_elements(char *line, t_elements *elements)
{
	char	*value;

	value = get_line_value(line);
	if (ft_strncmp(line, "NO ", 3) == 0 && texture_open(value))
		elements->no = get_line_value(line);
	else if (ft_strncmp(line, "SO ", 3) == 0
			&& texture_open(value))
		elements->so = get_line_value(line);
	else if (ft_strncmp(line, "WE ", 3) == 0 && texture_open(value))
		elements->we = get_line_value(line);
	else if (ft_strncmp(line, "EA ", 3) == 0 && texture_open(value))
		elements->ea = get_line_value(line);
	else if (ft_strncmp(line, "F ", 2) == 0)
		elements->f = get_line_value(line);
	else if (ft_strncmp(line, "C ", 2) == 0)
		elements->c = get_line_value(line);
	else
	{
		free(value);
		return (0);
	}
	free(value);
	return (1);
}
