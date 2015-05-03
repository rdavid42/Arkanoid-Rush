/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:19 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:19 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			init(t_core *c)
{
	if (!glfwInit())
		return (0);
	c->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
								"Arkanoid", NULL, NULL);
	if (!c->window)
	{
		glfwTerminate();
		return (0);
	}
	glfwMakeContextCurrent(c->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(c->window, key_callback);
	c->levels = NULL;
	init_core(c);
	if (!init_font(c))
		return (0);
	if (!init_core(c))
		return (0);
	return (1);
}
