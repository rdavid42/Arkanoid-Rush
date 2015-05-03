
#include "core.h"

void		render(t_core *c)
{
	draw_ui(c);
	draw_current_level(c);
	draw_player(&c->player);
	draw_ball(&c->ball);
	if (c->game_over)
		draw_game_over(c);
	else if (c->win)
		draw_win(c);
}
