/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itrs_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:57 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:46:57 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			itrs_h(t_circle *c, float x, float y, float s)
{
	if (c->p.x >= x && c->p.x <= x + s
		&& c->p.y + c->r > y && c->p.y - c->r < y)
		return (1);
	return (0);
}
