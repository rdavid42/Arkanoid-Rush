
#include <stdlib.h>
#include "core.h"

void		release_levels(t_core *c)
{
	int		i;
	int		j;

	j = -1;
	while (++j < NLEVEL)
	{
		i = -1;
		while (++i < GRID_HEIGHT)
			free(c->levels[j].grid[i]);
		free(c->levels[j].grid);
		c->levels[j].grid = NULL;
	}
	free(c->levels);
}
