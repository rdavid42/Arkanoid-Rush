
#include "core.h"

void		init_up_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = 0;
	b->y = 0;
	b->w = LEVEL_WIDTH + BLOC_WIDTH;
	b->h = BLOC_HEIGHT;
}
