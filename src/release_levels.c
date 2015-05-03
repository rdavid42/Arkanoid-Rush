/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_levels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:00 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:00 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"

void		release_levels(t_core *c)
{
	int		i;
	int		j;

	j = -1;
	while (++j < NLEVEL)
	{
		i = -1;
		while (++i < GRID_HEIGHT)
			free(c->levels[j].grid[i]);
		free(c->levels[j].grid);
		c->levels[j].grid = NULL;
	}
	free(c->levels);
}
