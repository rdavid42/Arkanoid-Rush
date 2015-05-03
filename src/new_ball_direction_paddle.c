/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ball_direction_paddle.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:43 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:43 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		new_ball_direction_paddle(t_ball *b)
{
	b->d.x += (1 - ANGULAR_FACTOR) * PLAYER_SPEED * MASS_FACTOR * FRICTION;
	b->d.y = -b->d.y;
}
