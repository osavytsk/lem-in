/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:53:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:39 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			best_way(t_area *begin, t_binds *way)
{
	t_binds	*binds;

	binds = begin->binds;
	while (binds)
	{
		if (binds->bind->condition == 2)
		{
			making_way(way, binds->bind);
			return (1);
		}
		binds = binds->nxt;
	}
	return (0);
}

int			ft_routing(t_area *area, t_binds *way, int i, int max)
{
	t_binds	*binds;

	binds = area->binds;
	area->intent = 1;
	if (area->condition == 2)
		return (1);
	if (i > max)
	{
		delete_way(way);
		area->intent = 0;
		return (0);
	}
	while (binds)
	{
		if (binds->bind->intent == 0 || binds->bind->condition == 2)
		{
			if (making_way(way, binds->bind) &&
					ft_routing(binds->bind, way, i + 1, max))
				return (1);
			else
				binds->bind->intent = 0;
		}
		binds = binds->nxt;
	}
	delete_way(way);
	return (0);
}

t_binds		**find_path(t_area *begin, t_area *area, int paths)
{
	t_binds	**way;
	int		i;
	int		binds;

	i = 0;
	binds = 0;
	way = way_setup(begin, paths);
	if (best_way(begin, way[i]))
		return (way);
	while (binds < numbers_of_area(area) && i < paths)
	{
		if (ft_routing(begin, way[i], 0, binds))
			i++;
		else
			binds++;
	}
	return (way);
}

t_binds		**way_setup(t_area *begin, int paths)
{
	t_binds	**way;

	way = (t_binds**)malloc(sizeof(t_binds*) * paths + 1);
	way[paths--] = NULL;
	while (paths >= 0)
	{
		way[paths] = malloc(sizeof(t_binds));
		way[paths]->bind = begin;
		way[paths]->nxt = NULL;
		paths--;
	}
	return (way);
}
