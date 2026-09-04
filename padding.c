static void	width_and_height(char **map_line, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->width = 0;
	while (map_line[i])
		i++;
	map->height = i;
	i = 0;
	while (map_line[i])
	{
		j = 0;
		while (map_line[i][j])
			j++;
		if (j > map->width)
			map->width = j;
		i++;
	}
}

void	padding(t_map *map)
{
	int		i;
	int		j;
	int		space;
	char	**map_line;
	char	*tmp;

	if (!find_map(map->map, &i))
	{
		printf("Error while finding map\n");
		return ;
	}
	map_line = map->map + i;
	i = 0;
	width_and_height(map_line, map);
	while (map_line[i])
	{
		tmp = malloc(ft_strlen(map_line[i]) + 1);
		if (!tmp)
			return ;
		ft_memcpy(tmp, map_line[i], ft_strlen(map_line[i]));
		free(map_line[i]);
		map_line[i] = malloc(map->width + 1);
		if (!map_line[i])
		{
			free(tmp);
			return ;
		}
		space = map->width - ft_strlen(tmp);
		j = 0;
		while (j < space)
		{
			map_line[i][j] = ' ';
			j++;
		}
		ft_memcpy(map_line[i] + space, tmp, ft_strlen(tmp));
		map_line[i][map->width] = '\0';
		free(tmp);
		i++;
	}
}
