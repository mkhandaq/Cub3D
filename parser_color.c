#include "cub.h"

static int	color_value(char *color, int *i)
{
	int	value;
	int	digits;

	value = 0;
	digits = 0;
	while (ft_isdigit(color[*i]))
	{
		if (value > 25 || (value == 25 && color[*i] > '5'))
			return (-1);
		value = value * 10 + color[*i] - '0';
		digits = 1;
		(*i)++;
	}
	if (!digits)
		return (-1);
	return (value);
}

int	check_color(char *color)
{
	int	i;
	int	count;
	int	value;

	i = 0;
	count = 0;
	while (color[i])
	{
		value = color_value(color, &i);
		if (value < 0)
			return (0);
		count++;
		if (color[i] && (color[i++] != ',' || count == 3))
			return (0);
	}
	return (count == 3);
}
