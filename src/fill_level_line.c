/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_level_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:00 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:00 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		fill_level_line(t_level *l, t_bloc *bline, char *line)
{
	int					i;

	i = -1;
	while (++i < GRID_WIDTH)
	{
		if (line[i] != '.')
		{
			bline[i].life = line[i] - 48;
			l->current_blocks++;
		}
		else
			bline[i].life = 0;
	}
}
