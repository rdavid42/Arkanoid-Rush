
#include "core.h"

int			itrs_h(t_circle *c, float x, float y, float s)
{
	if (c->p.x >= x && c->p.x <= x + s
		&& c->p.y + c->r > y && c->p.y - c->r < y)
		return (1);
	return (0);
}
