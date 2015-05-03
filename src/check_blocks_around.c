
#include "core.h"

int			check_blocks_around(t_core *c, int x, int y)
{
	int						i;

	if (y >= 0 && x >= 0 && y < GRID_HEIGHT && x < GRID_WIDTH)
	{
		i = -1;
		while (++i < 5)
		{
			if (check_block(x, y, i, c))
				return (1);
		}
	}
	return (0);
}
