/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:45:04 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:45:05 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_vec		get_vec(float x, float y)
{
	t_vec	n;

	n.x = x;
	n.y = y;
	return (n);
}