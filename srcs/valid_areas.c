/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_areas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 23:16:16 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		check_area_specific(t_area *begin, char **array)
{
	if (!array[0] || !array[1] || !array[2] || array[3]
		|| array[0][0] == 'L' || array[0][0] == '#'
		|| !simply_number(array[1]) || !simply_number(array[2])
		|| !check_ident_area(begin, array[0])
		|| (array[1][0] == '0' && array[1][1])
		|| (array[2][0] == '0' && array[2][1])
		|| !checking_coord(begin, ft_atoi(array[1]), ft_atoi(array[2])))
		return (0);
	else
		return (1);
}

int		checking_coord(t_area *begin, int crd_x, int crd_y)
{
	while (begin->nxt_area != NULL)
	{
		begin = begin->nxt_area;
		if (begin->coord_x == crd_x && begin->coord_y == crd_y)
			return (0);
	}
	return (1);
}

int		check_ident_area(t_area *begin, char *ident)
{
	while (begin->nxt_area != NULL)
	{
		begin = begin->nxt_area;
		if (ft_strequ(begin->ident, ident))
			return (0);
	}
	return (1);
}

int		check_area_condition(int condition, t_area *area)
{
	while (area->nxt_area)
	{
		area = area->nxt_area;
		if (area->condition == condition)
			return (0);
	}
	return (1);
}

void	set_intent(t_area *areas)
{
	while (areas)
	{
		areas->intent = 0;
		areas = areas->nxt_area;
	}
}
