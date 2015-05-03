
#include "core.h"

t_vec		new_ball_direction(t_ball *b, t_vec const n)
{
	t_vec	new;
	float	dp;

	dp = -dot_product(&n, &b->d);
	new.x = b->d.x + (2 * n.x * dp);
	new.y = b->d.y + (2 * n.y * dp);
	return (new);
}
