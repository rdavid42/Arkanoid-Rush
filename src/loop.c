
#include "core.h"

void		loop(t_core *c)
{
	gl_enable_2d(0, 0);
	while (!glfwWindowShouldClose(c->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		inputs(c);
		update(c);
		render(c);
		glfwSwapBuffers(c->window);
		glfwPollEvents();
	}
	gl_disable_2d();
}
