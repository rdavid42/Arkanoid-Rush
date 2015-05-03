
#include "core.h"

void		draw_game_over(t_core *c)
{
	char const	*g = "GAME OVER ! PRESS SPACE OR ESCAPE";
	int const	l = slen(g);
	int const	w = l * (c->rdf->cw * c->rdf->s) + (l - 2) * c->rdf->p;
	int const	h = c->rdf->ch * c->rdf->s;

	(void)c;
	draw_text(c->rdf, g,
			WINDOW_WIDTH / 2 - w / 2, WINDOW_HEIGHT / 2 - h / 2);
}
