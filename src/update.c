/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:27 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:27 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		update(t_core *c)
{
	int		i;

	if (!c->game_over || c->win)
	{
		i = 0;
		while (++i < 5)
			update_ball(c);
		if (c->ball.c.p.x > WINDOW_WIDTH || c->ball.c.p.y > WINDOW_HEIGHT
			|| c->ball.c.p.x < 0 || c->ball.c.p.y < 0)
		{
			c->lives = c->lives - 1 < 0 ? 0 : c->lives - 1;
			init_ball(c);
		}
		if (c->lives <= 0)
			c->game_over = 1;
		if (c->levels[c->cl].current_blocks <= 0)
		{
			c->cl++;
			init_ball(c);
			init_player(c);
		}
		if (c->cl >= NLEVEL - 1)
			c->win = 1;
	}
}
