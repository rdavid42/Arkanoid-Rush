/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bloc_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:05 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:06 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_bloc_borders(float x, float y)
{
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y);
	glEnd();
}
