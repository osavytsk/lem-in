/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputResults.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:04:23 by osavytsk         ###   ########.fr       */
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
	int turn;
	int	i;

	exsts = 0;
	i = 0;
	while (its->ants[i])
	{
		if (checkAnt(its, i))
		{
			if (exsts > 0)
				ft_printf(" ");
			path = its->ants[i]->path;
			turn = its->ants[i]->turn;
			ft_printf("L%d-%s", its->ants[i]->ids,
					its->rooms[its->paths[path]->path[turn]]->ids);
			exsts = 1;
			its->ants[i]->turn++;
			if (its->paths[path]->lenght <= its->ants[i]->turn)
				its->ants[i]->turn = -1;
		}
		i++;
	}
	return (exsts);
}

void		outputResults(t_data *its, int lst, char **fl)
{
	int	turns;

    outputFile(its, fl, lst);
	if (lst == 0)
		return ;
	if (its->putAllWays)
		outputAllPaths(its);
	else if (its->putWays)
		outputPaths(its);
	if (its->putMap)
		vsPutMap(its);
	if (its->putAntMove)
		turns = outputAntMoves(its);
	else
	{
		turns = 0;
		while (printAnts(its))
		{
			ft_printf("\n");
			turns++;
		}
	}
	if (its->putMoves)
		ft_printf("\n{green}MOVES: %d{eoc}\n", turns);
}
