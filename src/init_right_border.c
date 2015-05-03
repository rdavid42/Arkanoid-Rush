/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_right_border.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:18 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:46:18 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		init_right_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = LEVEL_WIDTH + BLOC_WIDTH / 2;
	b->y = BLOC_HEIGHT;
	b->w = BLOC_WIDTH / 2;
	b->h = LEVEL_HEIGHT;
}
