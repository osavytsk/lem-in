/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addLink.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:55:52 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:20:20 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

int		addLink(t_data *its, int roomFirst, int roomSecond)
{
	t_links	**links;
	int		i;
	int		lenght;

	lenght = 0;
	while (its->nodes && its->nodes[lenght])
		lenght++;
	links = (t_links **)malloc(sizeof(t_links *) * (lenght + 2));
	i = 0;
	while (i < lenght)
	{
		links[i] = its->nodes[i];
		i++;
	}
	links[i] = (t_links *)malloc(sizeof(t_links));
	links[i]->roomFirst = roomFirst;
	links[i]->roomSecond = roomSecond;
	links[i + 1] = NULL;
	if (its->nodes)
		free(its->nodes);
	its->nodes = links;
	return (i);
}
