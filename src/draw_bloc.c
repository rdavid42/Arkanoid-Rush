
#include "core.h"

void		draw_bloc(float x, float y)
{
	glBegin(GL_QUADS);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + BLOC_HEIGHT - 2);
	glVertex2f(x + 1, y + BLOC_HEIGHT - 2);
	glEnd();
}
