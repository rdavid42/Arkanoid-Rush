/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itrs_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:02 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:02 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			itrs_v(t_circle *c, float x, float y, float s)
{
	if (c->p.y >= y && c->p.y <= y + s
		&& c->p.x + c->r > x && c->p.x - c->r < x)
		return (1);
	return (0);
}
