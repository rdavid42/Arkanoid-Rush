
#include "core.h"

void		init_left_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = 0;
	b->y = BLOC_HEIGHT;
	b->w = BLOC_WIDTH / 2;
	b->h = LEVEL_HEIGHT;
}
