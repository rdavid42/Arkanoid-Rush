
#include "core.h"

void		draw_text(t_font *f, char const *t, float x, float y)
{
	int		i;
	int		j;
	float	px;

	glBegin(GL_QUADS);
	px = x;
	while (*t)
	{
		j = -1;
		while (++j < f->ch)
		{
			i = -1;
			while (++i < f->cw)
			{
				if (f->c[(unsigned char)*t][j][i] == '#')
					draw_letter_quad(px + i * f->s, y + j * f->s, f->s);
			}
		}
		++t;
		px += f->cw * f->s + f->p;
	}
	glEnd();
}
