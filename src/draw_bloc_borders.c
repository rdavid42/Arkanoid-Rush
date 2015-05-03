
#include "core.h"

void		draw_bloc_borders(float x, float y)
{
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y);
	glEnd();
}
