/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:51 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put_conversion.h"

static char	*handle_float(long double nbr, t_conversion *conv)
{
	char	tmp[FLOAT_SIZE];

	if (conv->type == 'a' || conv->type == 'A')
		return (pf_handle_a(nbr, conv));
	if (conv->precision < 0)
		conv->precision = 6;
	pf_ftoa_conv(tmp, nbr, conv);
	return (ft_strdup(tmp));
}

void		pf_put_float(t_conversion *conv, va_list valist)
{
	size_t	margin;
	char	*str;

	if (conv->ldouble)
		str = handle_float(va_arg(valist, long double), conv);
	else
		str = handle_float(va_arg(valist, double), conv);
	margin = (size_t)(conv->sign || str[0] == '-');
	if (conv->type == 'a' || conv->type == 'A')
		margin += 2;
	if (conv->sign && str[0] != '-')
		str = pf_strjoinchr(str, conv->sign, 1, BEGIN);
	conv->precision = -1;
	str = pf_handle_minwidth(conv, str, margin);
	pf_putstr(str);
	free(str);
}
