/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ball.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:32 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:32 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		update_ball(t_core *c)
{
	int						x;
	int						y;
	int						r;
	static t_vec			n[4] =

	{ {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	x = c->ball.c.p.x / BLOC_WIDTH - 1;
	y = c->ball.c.p.y / BLOC_HEIGHT - 1;
	if ((r = check_platform(c)) != -1)
		new_ball_direction_paddle(&c->ball);
	else if (itrs_v(&c->ball.c, LEVEL_X + LEVEL_WIDTH, LEVEL_Y, LEVEL_HEIGHT))
		c->ball.d = new_ball_direction(&c->ball, n[0]);
	else if (itrs_v(&c->ball.c, LEVEL_X, LEVEL_Y, LEVEL_HEIGHT))
		c->ball.d = new_ball_direction(&c->ball, n[1]);
	else if (itrs_h(&c->ball.c, LEVEL_X, LEVEL_Y, LEVEL_WIDTH))
		c->ball.d = new_ball_direction(&c->ball, n[2]);
	check_blocks_around(c, x, y);
	c->ball.c.p.x += c->ball.d.x / 5;
	c->ball.c.p.y += c->ball.d.y / 5;
}
