/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:26:40 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put_conversion.h"

void		pf_put_signed(t_conversion *conv, long long number)
{
	size_t	margin;
	char	*nbr;

	margin = (size_t)(conv->sign || number < 0);
	nbr = ft_itoa_base(number, 10);
	if (conv->sign && number >= 0)
		nbr = pf_strjoinchr(nbr, conv->sign, 1, BEGIN);
	if (conv->apostrophe)
		nbr = pf_handle_apostrophe(nbr);
	nbr = pf_handle_precision(conv, nbr, (int)margin, margin);
	if (!conv->precision && !number)
		nbr = pf_strclear(nbr);
	nbr = pf_handle_minwidth(conv, nbr, margin);
	pf_putstr(nbr);
	free(nbr);
}
