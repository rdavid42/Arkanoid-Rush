
#include "core.h"

void		draw_letter_quad(float x, float y, float s)
{
	glVertex2f(x, y);
	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x, y + s);
}
