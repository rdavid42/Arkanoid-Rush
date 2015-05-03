
#include "core.h"

void		draw_ball(t_ball *b)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(b->c.p.x - b->c.r, b->c.p.y - b->c.r);
	glVertex2f(b->c.p.x + b->c.r, b->c.p.y - b->c.r);
	glVertex2f(b->c.p.x + b->c.r, b->c.p.y + b->c.r);
	glVertex2f(b->c.p.x - b->c.r, b->c.p.y + b->c.r);
	glEnd();
}
