
#include "core.h"

int			check_block_return(t_bloc **g, t_core *c, int px, int py)
{
	g[py][px].life--;
	if (!g[py][px].life)
	{
		c->score += 100;
		c->levels[c->cl].current_blocks--;
	}
	else
		c->score += 150;
	return (1);
}