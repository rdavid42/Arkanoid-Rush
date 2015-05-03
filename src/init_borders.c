
#include "core.h"

void		init_borders(t_core *c)
{
	init_left_border(&c->b[0]);
	init_right_border(&c->b[1]);
	init_up_border(&c->b[2]);
}
