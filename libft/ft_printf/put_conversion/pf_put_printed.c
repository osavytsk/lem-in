/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_printed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:43 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put_conversion.h"

void	pf_put_printed(t_conversion *conv, va_list valist)
{
	void	*n;

	n = va_arg(valist, void *);
	if (conv->size == N)
		*((int *)n) = pf_printed_count();
	else if (conv->size == HH)
		*((char *)n) = (char)pf_printed_count();
	else if (conv->size == H)
		*((short *)n) = (short)pf_printed_count();
	else if (conv->size == L)
		*((long *)n) = pf_printed_count();
	else if (conv->size == LL)
		*((long long *)n) = pf_printed_count();
	else if (conv->size == Z)
		*((ssize_t *)n) = pf_printed_count();
	else if (conv->size == J)
		*((intmax_t *)n) = pf_printed_count();
}
