/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:16 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parse_all.h"

size_t		pf_parse_type(const char *f, size_t i, t_conversion *form)
{
	if (ft_strcchr("SDOUC", f[i]))
	{
		form->size = L;
		form->type = (char)ft_tolower(f[i]);
	}
	else
		form->type = f[i];
	return (i + 1);
}
