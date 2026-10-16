#include "cub.h"

void	init_elements(t_elements *elements)
{
	elements->no = NULL;
	elements->so = NULL;
	elements->we = NULL;
	elements->ea = NULL;
	elements->f = NULL;
	elements->c = NULL;
}

void	free_elements(t_elements *elements)
{
	free(elements->no);
	free(elements->so);
	free(elements->we);
	free(elements->ea);
	free(elements->f);
	free(elements->c);
}

void	parser_error(int fd, char **lines, t_elements *elements, char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	free_map(lines);
	free_elements(elements);
	if (fd >= 0)
		close(fd);
	exit(1);
}

int	element_seen(char *line, t_elements *elements)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (elements->no != NULL);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (elements->so != NULL);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (elements->we != NULL);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (elements->ea != NULL);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (elements->f != NULL);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (elements->c != NULL);
	return (-1);
}
