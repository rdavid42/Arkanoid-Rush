#ifndef CORE_H
# define CORE_H

# include <GLFW/glfw3.h>

typedef struct			s_core
{
	GLFWwindow			*window;
}						t_core;

void					error_callback(int error, const char *description);
int						slen(char const *str);
void					release_resources(t_core *c);
int						init(t_core *c);

#endif