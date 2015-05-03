/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:11 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:46:11 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		init_player(t_core *c)
{
	c->player.lives = 3;
	c->player.x = (LEVEL_WIDTH / 2) - (PLAYER_WIDTH / 2);
	c->player.y = LEVEL_HEIGHT - BLOC_HEIGHT;
}
