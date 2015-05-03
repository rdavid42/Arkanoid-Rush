
#include "core.h"

void		release_resources(t_core *c)
{
	glfwDestroyWindow(c->window);
	glfwTerminate();
}
