/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_font.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:55 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:55 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "core.h"

int			parse_font(t_font *f, char *n)
{
	int const		lsize = f->cw * f->ch + f->ch;
	char			p[2];
	char			l[lsize];
	int				fd;
	int				e[2];

	if ((fd = open(n, O_RDONLY, 0755)) == -1)
		return (0);
	while (42)
	{
		e[0] = read(fd, p, 2);
		e[1] = read(fd, l, lsize);
		if (e[0] == -1 || e[1] == -1)
			return (close(fd));
		if (!e[0] || !e[1] || e[0] != 2 || e[1] != lsize)
			break;
		if (!fill_font_letter(f, p[0], l))
			return (close(fd));
	}
	return (!close(fd));
}
