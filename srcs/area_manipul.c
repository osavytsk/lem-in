/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_manipul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 00:13:08 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:17 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_area		*get_area(t_area *begin, int condition)
{
	while (begin)
	{
		if (begin->condition == condition)
			return (begin);
		begin = begin->nxt_area;
	}
	return (NULL);
}

int			numbers_of_area(t_area *area)
{
	int		i;

	i = 0;
	while (area)
	{
		area = area->nxt_area;
		i++;
	}
	return (i);
}
