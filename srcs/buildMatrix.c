/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildMatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:29:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:05 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	linkExsts(t_data *its, int r1, int r2)
{
	int	i;

	i = 0;
	while (its->nodes && its->nodes[i])
	{
		if (its->nodes[i]->roomFirst == r1 && its->nodes[i]->roomSecond == r2)
			return (1);
		if (its->nodes[i]->roomFirst == r2 && its->nodes[i]->roomSecond == r1)
			return (1);
		i++;
	}
	return (0);
}

void		buildMatrix(t_data *its)
{
	int	i;
	int	j;

	its->size = 0;
	while (its->rooms && its->rooms[its->size])
		its->size++;
	its->mtx = (int **)malloc(sizeof(int *) * its->size);
	i = 0;
	while (i < its->size)
	{
		its->mtx[i] = (int *)malloc(sizeof(int) * its->size);
		j = 0;
		while (j < its->size)
		{
			its->mtx[i][j] = linkExsts(its, i, j);
			j++;
		}
		i++;
	}
}
