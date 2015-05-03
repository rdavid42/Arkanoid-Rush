/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:31 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:31 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_player(t_player *p)
{
	glColor3f(1.0f, 0.67f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(p->x, p->y);
	glVertex2f(p->x + PLAYER_WIDTH, p->y);
	glVertex2f(p->x + PLAYER_WIDTH, p->y + PLAYER_HEIGHT);
	glVertex2f(p->x, p->y + PLAYER_HEIGHT);
	glEnd();
}
