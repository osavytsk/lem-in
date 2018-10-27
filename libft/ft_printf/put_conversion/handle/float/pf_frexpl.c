/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_frexpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:29:12 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:30:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_float.h"

/*
** re-writen original frexpl function from math.h
*/

long double	pf_frexpl(long double value, int *e)
{
	int			exponent;

	if (value == 0.0 || value == -0.0)
	{
		*e = 0;
		return (value);
	}
	exponent = 0;
	while (value < 0.5)
	{
		value *= 2.0;
		exponent--;
	}
	while (value >= 1.0)
	{
		value *= 0.5;
		exponent++;
	}
	*e = exponent;
	return (value);
}
