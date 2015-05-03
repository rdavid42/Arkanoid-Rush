/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:16 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:16 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "core.h"

int			load_level(t_core *c, char const *name, int l)
{
	int		fd;
	int		i;
	char	buf[GRID_WIDTH + 1];
	int		ret;

	if (!allocate_level(&c->levels[l]))
		return (0);
	c->levels[l].current_blocks = 0;
	if ((fd = open(name, O_RDONLY, 0755)) == -1)
		return (0);
	i = -1;
	while (++i < GRID_HEIGHT + 2)
	{
		ret = read(fd, buf, GRID_WIDTH + 1);
		if (buf[GRID_WIDTH] != '\n')
			return (close(fd));
		if (ret == -1)
			return (close(fd));
		if (ret == 0)
			return (!close(fd));
		if (!check_line_errors(buf))
			return (close(fd));
		fill_level_line(&c->levels[l], c->levels[l].grid[i], buf);
	}
	return (!close(fd));
}
