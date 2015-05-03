/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:06 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:06 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		release_resources(t_core *c)
{
	glfwDestroyWindow(c->window);
	glfwTerminate();
}
