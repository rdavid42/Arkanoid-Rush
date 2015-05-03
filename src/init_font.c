/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_font.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:44 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:45 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

int			init_font(t_core *c)
{
	if (!(c->rdf = load_font("font.rdf")))
		return (!write(2, "Failed to load font !\n", 22));
	return (1);
}
