/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:43:12 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:43:12 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			check_block(int x, int y, int i, t_core *c)
{
	t_bloc					**g = c->levels[c->cl].grid;
	int						px;
	int						py;
	int						r;
	static t_vec			n[5] =

	{ {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {0, 0} };
	px = x + n[i].x;
	py = y + n[i].y;
	if (py >= 0 && py < GRID_HEIGHT && px >= 0 && px < GRID_WIDTH
		&& g[py][px].life != 0)
	{
		r = itrs_block(&c->ball.c, LEVEL_X + px * BLOC_WIDTH,
						LEVEL_Y + py * BLOC_HEIGHT,
						get_vec(BLOC_WIDTH, BLOC_HEIGHT));
		if (r != -1)
		{
			c->ball.d = new_ball_direction(&c->ball, n[r]);
			return (check_block_return(g, c, px, py));
		}
	}
	return (0);
}
