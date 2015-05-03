/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_levels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:59 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:59 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "core.h"

int			init_levels(t_core *c)
{
	int						i;
	static char const		*n[NLEVEL] =

	{ "levels/1", "levels/2", "levels/3" };
	if (!(c->levels = (t_level *)malloc(sizeof(t_level) * NLEVEL)))
		return (0);
	i = -1;
	while (++i < NLEVEL)
	{
		if (!load_level(c, n[i], i))
		{
			if (write(2, "Missing level !\n", 16) == -1)
				return (0);
			return (0);
		}
	}
	return (1);
}
