/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:47:12 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:12 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"

t_font		*load_font(char *filename)
{
	t_font	*nf;

	if (!(nf = malloc(sizeof(t_font))))
		return (NULL);
	nf->cw = 5;
	nf->ch = 5;
	nf->s = 5;
	nf->p = 2;
	if (!parse_font(nf, filename))
		return (NULL);
	return (nf);
}
