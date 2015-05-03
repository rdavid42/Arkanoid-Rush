
#include "core.h"

void		draw_current_level(t_core *c)
{
	int						x;
	int						y;
	int						i;
	static float const		cl[NB][3] =

	{ { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0, 1, 1 } };
	y = -1;
	while (++y < GRID_HEIGHT)
	{
		x = -1;
		while (++x < GRID_WIDTH)
		{
			i = c->levels[c->cl].grid[y][x].life;
			if (i != 0)
			{
				glColor3f(cl[i - 1][0], cl[i - 1][1], cl[i - 1][2]);
				draw_bloc(LEVEL_X + x * BLOC_WIDTH, LEVEL_Y + y * BLOC_HEIGHT);
			}
		}
	}
}
