/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_platform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:43:39 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:43:39 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			check_platform(t_core *c)
{
	if (itrs_v(&c->ball.c, c->player.x, c->player.y, PLAYER_HEIGHT))
		return (0);
	else if (itrs_v(&c->ball.c, c->player.x + PLAYER_WIDTH,
					c->player.y, PLAYER_HEIGHT))
		return (1);
	else if (itrs_h(&c->ball.c, c->player.x, c->player.y + PLAYER_HEIGHT,
					PLAYER_WIDTH))
		return (2);
	else if (itrs_h(&c->ball.c, c->player.x, c->player.y, PLAYER_WIDTH))
		return (3);
	return (-1);
}
