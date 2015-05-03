/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:34 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:46:35 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
