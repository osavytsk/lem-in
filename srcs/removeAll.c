/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeAll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 20:29:08 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:13:14 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			removeAll(t_data *its)
{
	int index;

	index = 0;
	while (its->rooms && its->rooms[index])
	{
		free(its->rooms[index]->ids);
		free(its->rooms[index++]);
	}
	if (its->rooms)
		free(its->rooms);
	index = 0;
	while (its->nodes && its->nodes[index])
		free(its->nodes[index++]);
	if (its->nodes)
		free(its->nodes);
	if (its->input)
		free(its->input);
	removeNext(its);
	free(its);
	return (0);
}
