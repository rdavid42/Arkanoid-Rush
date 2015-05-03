
#include "core.h"

void		new_ball_direction_paddle(t_ball *b)
{
	b->d.x += (1 - ANGULAR_FACTOR) * PLAYER_SPEED * MASS_FACTOR * FRICTION;
	b->d.y = -b->d.y;
}
