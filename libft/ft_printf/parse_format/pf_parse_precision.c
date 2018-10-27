/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:25:53 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parse_all.h"

size_t	pf_parse_precision(const char *f, size_t i, t_conversion *form,
		va_list v)
{
	if (f[i] == '.')
	{
		i++;
		form->precision = 0;
		if (ft_isdigit(f[i]))
		{
			form->precision = ft_atoi(f + i);
			while (ft_isdigit(f[i]))
				i++;
		}
		else if (f[i] == '*')
		{
			form->precision = va_arg(v, int);
			i++;
		}
	}
	return (i);
}
