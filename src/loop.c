/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:21 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:21 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
