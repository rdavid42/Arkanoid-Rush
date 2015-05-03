/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:44:50 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:44:51 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core.h"

void		error_callback(int error, const char *description)
{
	int		v;

	v = write(2, description, slen(description));
	(void)v;
	(void)error;
}
