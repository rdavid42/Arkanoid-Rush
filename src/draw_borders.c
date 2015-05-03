
#include "core.h"

void		draw_borders(t_border *b, int n)
{
	int		i;

	glBegin(GL_QUADS);
	i = -1;
	while (++i < n)
	{
		glColor3f(b[i].c[0], b[i].c[1], b[i].c[2]);
		glVertex2f(b[i].x, b[i].y);
		glVertex2f(b[i].x + b[i].w, b[i].y);
		glVertex2f(b[i].x + b[i].w, b[i].y + b[i].h);
		glVertex2f(b[i].x, b[i].y + b[i].h);
	}
	glEnd();
}
