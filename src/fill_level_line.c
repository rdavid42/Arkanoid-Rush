
#include "core.h"

void		fill_level_line(t_level *l, t_bloc *bline, char *line)
{
	int					i;

	i = -1;
	while (++i < GRID_WIDTH)
	{
		if (line[i] != '.')
		{
			bline[i].life = line[i] - 48;
			l->current_blocks++;
		}
		else
			bline[i].life = 0;
	}
}
