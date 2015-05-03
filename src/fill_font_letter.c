/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_font_letter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:55 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:55 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			fill_font_letter(t_font *f, unsigned char l, char *buf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < f->ch)
	{
		x = -1;
		while (++x < f->cw)
			f->c[l][y][x] = buf[y * (f->cw + 1) + x];
	}
	return (1);
}
