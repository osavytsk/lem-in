/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:25:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_parse_all.h"

static void	set_size(t_conversion *form, t_size new)
{
	if (form->size >= new)
		return ;
	form->size = new;
}

size_t		pf_parse_size(const char *f, size_t i, t_conversion *form)
{
	if (f[i] == 'h')
	{
		if (f[i + 1] == 'h' && i++)
			set_size(form, HH);
		else
			set_size(form, H);
	}
	else if (f[i] == 'l')
	{
		if (f[i + 1] == 'l' && i++)
			set_size(form, LL);
		else
			set_size(form, L);
	}
	else if (f[i] == 'j')
		set_size(form, J);
	else if (f[i] == 'z')
		set_size(form, Z);
	else
		return (i);
	return (i + 1);
}
