/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputAntMoves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:04:01 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	checkAnt(t_data *its, int i)
{
	int	j;

	if (its->ants[i]->turn < 0)
		return (0);
	j = 0;
	while (its->ants[j])
	{
		if (j != i && its->ants[j]->path == its->ants[i]->path)
		{
			if (its->ants[j]->turn == (its->ants[i]->turn + 1))
				return (0);
		}
		j++;
	}
	return (1);
}

static int	printAnts(t_data *its)
{
	int	exsts;
	int	path;
	int	i;

	exsts = 0;
	i = 0;
	while (its->ants[i])
	{
		if (checkAnt(its, i))
		{
			path = its->ants[i]->path;
			exsts = 1;
			its->ants[i]->turn++;
			if (its->paths[path]->lenght <= its->ants[i]->turn)
				its->ants[i]->turn = -1;
		}
		i++;
	}
	return (exsts);
}

static void	outOne(t_data *its, int **antMoves, int turns)
{
	int	j;
	int	i;

	j = 0;
	while (j < its->antsIndex)
	{
		antMoves[j][0] = its->ants[j]->turn++;
		j++;
	}
	i = 1;
	while (printAnts(its))
	{
		j = 0;
		while (j < its->antsIndex)
		{
			antMoves[j][i] = its->ants[j]->turn;
			j++;
		}
		i++;
	}
	outputResult(its, turns, antMoves);
}

int			outputAntMoves(t_data *its)
{
	int	**antMoves;
	int	i;
	int	turns;

	turns = 0;
	while (printAnts(its))
		turns++;
	antMoves = (int **)malloc(sizeof(int *) * (its->antsIndex));
	i = 0;
	while (i < its->antsIndex)
	{
		antMoves[i] = (int *)malloc(sizeof(int) * (turns + 1));
		its->ants[i]->turn = 0;
		i++;
	}
	outOne(its, antMoves, turns + 1);
	i = 0;
	while (i < its->antsIndex)
	{
		its->ants[i]->turn = 1;
		free(antMoves[i]);
		i++;
	}
	free(antMoves);
	return (turns);
}
