/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:28:18 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_put.h"

void	pf_putstr(char const *s)
{
	size_t size;

	size = 0;
	while (s[size])
		size++;
	pf_write(s, size);
}
