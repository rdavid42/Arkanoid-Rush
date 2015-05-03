/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ball_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:38 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:38 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_vec		new_ball_direction(t_ball *b, t_vec const n)
{
	t_vec	new;
	float	dp;

	dp = -dot_product(&n, &b->d);
	new.x = b->d.x + (2 * n.x * dp);
	new.y = b->d.y + (2 * n.y * dp);
	return (new);
}
