/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:25:54 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:21 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int			slen(char const *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
