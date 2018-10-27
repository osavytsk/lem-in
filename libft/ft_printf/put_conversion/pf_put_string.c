/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:36 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put_conversion.h"

void		pf_put_string(t_conversion *conv, va_list valist)
{
	char	*str;

	if (conv->size == L)
		str = pf_wstrtostr(va_arg(valist, wchar_t *), conv->precision);
	else
	{
		if (!(str = va_arg(valist, char *)))
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	str = ft_strcut(str, conv->precision);
	conv->precision = -1;
	str = pf_handle_minwidth(conv, str, 0);
	pf_putstr(str);
	free(str);
}
