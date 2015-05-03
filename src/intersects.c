
#include "core.h"

int			intersects(t_circle *c, t_rect *r)
{
	float	corner_dist;
	t_vec	dist;

	dist.x = op_abs(c->p.x - r->p.x);
	dist.y = op_abs(c->p.y - r->p.y);
	if (dist.x > (r->w / 2.0f + c->r))
		return (0);
	if (dist.y > (r->h / 2.0f + c->r))
		return (0);
	if (dist.x <= (r->w / 2.0f))
		return (1);
	if (dist.y <= (r->h / 2.0f))
		return (1);
	corner_dist = op_pow2(dist.x - r->w / 2.0f) +
					op_pow2(dist.y - r->h / 2.0f);
	return (corner_dist <= (op_pow2(c->r)));
}
