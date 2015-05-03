/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:47 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:47 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_win(t_core *c)
{
	char const	*g = "YOU WIN ! PRESS SPACE OR ESCAPE";
	int const	l = slen(g);
	int const	w = l * (c->rdf->cw * c->rdf->s) + (l - 2) * c->rdf->p;
	int const	h = c->rdf->ch * c->rdf->s;

	(void)c;
	draw_text(c->rdf, g,
			WINDOW_WIDTH / 2 - w / 2, WINDOW_HEIGHT / 2 - h / 2);
}
