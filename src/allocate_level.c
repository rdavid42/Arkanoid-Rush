
#include <stdlib.h>
#include "core.h"

int			allocate_level(t_level *l)
{
	int		i;

	if (!(l->grid = (t_bloc **)malloc(sizeof(t_bloc *) * GRID_HEIGHT)))
		return (0);
	i = -1;
	while (++i < GRID_HEIGHT)
	{
		if (!(l->grid[i] = (t_bloc *)malloc(sizeof(t_bloc) * GRID_WIDTH)))
			return (0);
	}
	return (1);
}
