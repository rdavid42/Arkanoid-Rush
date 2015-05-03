/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:09 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:10 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		render(t_core *c)
{
	draw_ui(c);
	draw_current_level(c);
	draw_player(&c->player);
	draw_ball(&c->ball);
	if (c->game_over)
		draw_game_over(c);
	else if (c->win)
		draw_win(c);
}
