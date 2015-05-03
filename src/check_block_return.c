/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_block_return.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:43:18 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:43:18 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			check_block_return(t_bloc **g, t_core *c, int px, int py)
{
	g[py][px].life--;
	if (!g[py][px].life)
	{
		c->score += 100;
		c->levels[c->cl].current_blocks--;
	}
	else
		c->score += 150;
	return (1);
}
