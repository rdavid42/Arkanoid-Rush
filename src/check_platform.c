
#include "core.h"

int			check_platform(t_core *c)
{
	if (itrs_v(&c->ball.c, c->player.x, c->player.y, PLAYER_HEIGHT))
		return (0);
	else if (itrs_v(&c->ball.c, c->player.x + PLAYER_WIDTH,
					c->player.y, PLAYER_HEIGHT))
		return (1);
	else if (itrs_h(&c->ball.c, c->player.x, c->player.y + PLAYER_HEIGHT,
					PLAYER_WIDTH))
		return (2);
	else if (itrs_h(&c->ball.c, c->player.x, c->player.y, PLAYER_WIDTH))
		return (3);
	return (-1);
}
