
#include "core.h"

int			itrs_v(t_circle *c, float x, float y, float s)
{
	if (c->p.y >= y && c->p.y <= y + s
		&& c->p.x + c->r > x && c->p.x - c->r < x)
		return (1);
	return (0);
}
