/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exploration.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:55:25 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			making_way(t_binds *way, t_area *bind)
{
	t_binds	*new_way;

	while (way->nxt)
		way = way->nxt;
	new_way = malloc(sizeof(t_binds));
	new_way->bind = bind;
	new_way->nxt = NULL;
	way->nxt = new_way;
	return (1);
}

void		delete_way(t_binds *way)
{
	if (!way || !way->nxt)
		return ;
	while (way->nxt->nxt)
		way = way->nxt;
	free(way->nxt);
	way->nxt = NULL;
}

int			way_length(t_binds *way)
{
	int		i;

	i = 0;
	while (way->nxt)
	{
		i++;
		way = way->nxt;
	}
	return (i);
}
