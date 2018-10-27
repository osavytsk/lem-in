/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:28:34 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_handle.h"

char	*pf_handle_precision(t_conversion *c, char *str, int l, size_t m)
{
	int	count;

	count = c->precision - ((int)ft_strlen(str) - l);
	if (count > 0)
		str = pf_strjoinchr_begin(str, '0', count, m);
	return (str);
}
