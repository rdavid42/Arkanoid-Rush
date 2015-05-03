/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:42 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:42 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_ui(t_core *c)
{
	draw_borders(c->b, 3);
	glColor3f(1.0f, 1.0f, 1.0f);
	draw_text(c->rdf, "SCORE", LEVEL_WIDTH + BLOC_WIDTH + 20, BLOC_HEIGHT);
	draw_text(c->rdf, itoa(c->score), LEVEL_WIDTH + BLOC_WIDTH + 20,
									c->rdf->s * c->rdf->ch + 40);
	draw_text(c->rdf, "LIVES", LEVEL_WIDTH + BLOC_WIDTH + 20,
									c->rdf->s * c->rdf->ch * 2 + 60);
	draw_text(c->rdf, itoa(c->lives), LEVEL_WIDTH + BLOC_WIDTH + 20,
									c->rdf->s * c->rdf->ch * 3 + 80);
}
