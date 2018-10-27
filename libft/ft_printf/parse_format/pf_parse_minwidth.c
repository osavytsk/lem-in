/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_minwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:25:49 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parse_all.h"

size_t	pf_parse_minwidth(const char *f, size_t i, t_conversion *form,
							va_list v)
{
	if (ft_isdigit(f[i]))
	{
		form->minimum_width = ft_atoi(f + i);
		while (ft_isdigit(f[i]))
			i++;
	}
	else if (f[i] == '*')
	{
		form->minimum_width = va_arg(v, int);
		if (form->minimum_width < 0)
		{
			form->minimum_width = -form->minimum_width;
			form->padding = '-';
		}
		i++;
	}
	return (i);
}
