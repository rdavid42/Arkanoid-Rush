/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ball.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:23 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:23 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		init_ball(t_core *c)
{
	c->ball.c.r = BALL_RADIUS;
	c->ball.c.p.x = c->player.x + PLAYER_WIDTH / 2;
	c->ball.c.p.y = c->player.y - c->ball.c.r;
	set_vec(&c->ball.d, BALL_INI_SPEED, -BALL_INI_SPEED);
}
