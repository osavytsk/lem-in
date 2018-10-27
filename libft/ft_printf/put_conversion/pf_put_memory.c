/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:48 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put_conversion.h"

void	pf_put_memory(t_conversion *conv, va_list valist)
{
	char				*str;
	unsigned long long	memory;

	memory = (unsigned long long)va_arg(valist, void *);
	conv->type = 'x';
	conv->hashtag = 2;
	str = pf_utoa_base(memory, 16, conv->type, conv->hashtag);
	str = pf_handle_precision(conv, str, conv->hashtag, (size_t)conv->hashtag);
	if (!conv->precision && !memory)
		str = ft_strcut(str, 2);
	str = pf_handle_minwidth(conv, str, (size_t)conv->hashtag);
	pf_putstr(str);
	free(str);
}
