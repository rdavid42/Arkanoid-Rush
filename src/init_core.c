
#include "core.h"

int			init_core(t_core *c)
{
	c->score = 0;
	c->cl = 0;
	c->lives = INI_LIVES;
	c->game_over = 0;
	c->win = 0;
	init_player(c);
	init_ui(c);
	init_ball(c);
	init_borders(c);
	if (!init_levels(c))
		return (0);
	return (1);
}
