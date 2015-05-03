
#include <unistd.h>
#include "core.h"

int			init_font(t_core *c)
{
	if (!(c->rdf = load_font("font.rdf")))
		return (!write(2, "Failed to load font !\n", 22));
	return (1);
}
