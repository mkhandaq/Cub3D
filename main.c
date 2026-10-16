#include "cub.h"

int main (int argc, char **argv)
{
	t_map		map;
	t_player	player;

	parse_file(argc, argv, &map, &player);
	free_map(map.map);
	free_elements(&map.elements);
	printf("File opened successfully\n");
	return 0;
}