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

static void	removeTwoNext(t_data *its)
{
	int	index;

	index = 0;
	while (its->diff && its->diff[index])
	{
		free(its->diff[index]->paths);
		free(its->diff[index++]);
	}
	if (its->diff)
		free(its->diff);
}

static void	removeNext(t_data *its)
{
	int	index;

	index = 0;
	while (its->mtx && index < its->size)
		free(its->mtx[index++]);
	if (its->mtx)
		free(its->mtx);
	index = 0;
	while (its->allWays && its->allWays[index])
	{
		free(its->allWays[index]->path);
		free(its->allWays[index++]);
	}
	if (its->allWays)
		free(its->allWays);
	if (its->paths)
		free(its->paths);
	index = 0;
	while (its->ants && its->ants[index])
		free(its->ants[index++]);
	if (its->ants)
		free(its->ants);
	removeTwoNext(its);
}

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
