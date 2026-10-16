#include "cub.h"

static int	parse_elements(char **lines, t_elements *elements, int *start)
{
	int	i;
	int	count;
	int	seen;

	i = 0;
	count = 0;
	while (lines[i] && count < 6)
	{
		if (lines[i][0])
		{
			seen = element_seen(lines[i], elements);
			if (seen != 0 || !set_elements(lines[i], elements))
				return (0);
			count++;
		}
		i++;
	}
	if (count != 6 || !check_color(elements->f)
		|| !check_color(elements->c))
		return (0);
	while (lines[i] && !lines[i][0])
		i++;
	*start = i;
	return (lines[i] != NULL);
}

static char	**load_lines(int argc, char **argv, t_elements *elements,
	int *fd)
{
	int		check_fd;
	char	buffer[1];
	char	**lines;

	if (argc != 2 || ft_strlen(argv[1]) <= 4 || ft_strncmp(argv[1]
		+ ft_strlen(argv[1]) - 4, ".cub", 4))
		parser_error(-1, NULL, elements, "Invalid file extension");
	check_fd = open(argv[1], O_RDONLY);
	if (check_fd == -1 || read(check_fd, buffer, 1) == -1)
		parser_error(check_fd, NULL, elements, "Invalid file");
	close(check_fd);
	*fd = open(argv[1], O_RDONLY);
	lines = set_map(*fd, argv[1]);
	if (!lines)
		parser_error(*fd, NULL, elements, "Could not read file");
	return (lines);
}

static int	prepare_map(char **lines, t_map *map, int start)
{
	int	i;
	int	end;
	int	width;

	end = start;
	while (lines[end])
		end++;
	while (end > start && !lines[end - 1][0])
	{
		free(lines[--end]);
		lines[end] = NULL;
	}
	if (end == start)
		return (0);
	width = ft_strlen(lines[start]);
	i = start;
	while (i < end)
	{
		if ((int)ft_strlen(lines[i]) != width)
			return (0);
		i++;
	}
	i = 0;
	while (i < start)
		free(lines[i++]);
	i = 0;
	while (start < end)
		lines[i++] = lines[start++];
	lines[i] = NULL;
	map->map = lines;
	map->width = width;
	map->height = i;
	return (1);
}

static int	validate_map(t_map *map, t_player *player)
{
	if (!check_map_chars(map->map, map))
		return (0);
	if (!find_spawn(map->map, *map, player))
		return (0);
	return (check_map_closed(map->map, map, player));
}

int	parse_file(int argc, char **argv, t_map *map, t_player *player)
{
	int		fd;
	int		start;
	char	**lines;

	init_elements(&map->elements);
	lines = load_lines(argc, argv, &map->elements, &fd);
	if (!parse_elements(lines, &map->elements, &start)
		|| !prepare_map(lines, map, start)
		|| !validate_map(map, player))
		parser_error(fd, lines, &map->elements, "Invalid map");
	close(fd);
	return (1);
}
