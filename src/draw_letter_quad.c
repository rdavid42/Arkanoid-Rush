/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_letter_quad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:26 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:26 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw_letter_quad(float x, float y, float s)
{
	glVertex2f(x, y);
	glVertex2f(x + s, y);
	glVertex2f(x + s, y + s);
	glVertex2f(x, y + s);
}
