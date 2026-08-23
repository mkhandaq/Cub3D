#include "cub.h"

int main (int argc, char **argv)
{
	int	fd;
	if (argc != 2)
		return 1;
	if (ft_strlen(argv[1]) <= 4 ||
		ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
	{
		printf("Hwak Tuah\n");
		return 1;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("I MEAN WHAT THE FUCK OPEN?!\n");
		return 1;
	}
	close(fd);
	printf("perfect\n");
	return 0;
}