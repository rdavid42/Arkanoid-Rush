/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:07 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:07 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		key_callback(GLFWwindow *window, int key, int scancode,
						int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
