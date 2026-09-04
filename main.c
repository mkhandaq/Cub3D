#include "cub.h"

int main (int argc, char **argv)
{
	int		fd;
	char	**map;
	if (argc != 2)
		return 1;
	if (ft_strlen(argv[1]) <= 4 ||
		ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		printf("Error: Invalid file extension\n");
		return 1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Could not open file\n");
		return 1;
	}
	map = set_map(fd, argv[1]);
	if (!map)
		return 1;
	//print_map(map);
	close(fd);
	printf("File opened successfully\n");
	return 0;
}