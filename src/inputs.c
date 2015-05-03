
#include "core.h"

void		inputs(t_core *c)
{
	if (glfwGetKey(c->window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		if (c->player.x >= LEVEL_X + PLAYER_SPEED)
			c->player.x -= PLAYER_SPEED;
	}
	if (glfwGetKey(c->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		if (c->player.x + PLAYER_WIDTH <= LEVEL_X + LEVEL_WIDTH - PLAYER_SPEED)
			c->player.x += PLAYER_SPEED;
	}
	if (c->game_over && glfwGetKey(c->window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		release_levels(c);
		init_core(c);
	}
}
