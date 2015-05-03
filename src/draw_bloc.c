/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:43:57 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:43:59 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_bloc(float x, float y)
{
	glBegin(GL_QUADS);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + BLOC_HEIGHT - 2);
	glVertex2f(x + 1, y + BLOC_HEIGHT - 2);
	glEnd();
}
