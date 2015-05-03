/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itrs_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:46:52 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:46:52 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			itrs_block(t_circle *c, float x, float y, t_vec s)
{
	if (itrs_h(c, x, y, s.x))
		return (2);
	if (itrs_h(c, x, y + BLOC_HEIGHT, s.x))
		return (3);
	if (itrs_v(c, x + BLOC_WIDTH, y, s.y))
		return (1);
	if (itrs_v(c, x, y, s.y))
		return (0);
	return (-1);
}
