/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:25:50 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:47:30 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"

int			main(int argc, char **argv)
{
	t_core		c;

	if (!init(&c))
		return (0);
	loop(&c);
	release_resources(&c);
	release_levels(&c);
	free(c.rdf);
	(void)argc;
	(void)argv;
	return (1);
}
