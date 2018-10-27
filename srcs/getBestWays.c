/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getBestWays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 01:01:48 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:15:29 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	getBestWay(t_data *its, int difer)
{
	int bst;
	int	minimum;
	int	i;
	int	path;

	bst = 0;
	minimum = INFIN;
	i = 0;
	while (i < its->diff[difer]->lenght)
	{
		path = its->diff[difer]->paths[i];
		if (minimum > (its->paths[path]->lenght + its->paths[path]->ants))
		{
			bst = path;
			minimum = its->paths[path]->lenght + its->paths[path]->ants;
		}
		i++;
	}
	return (bst);
}

static void	cleanWays(t_data *its, int difer)
{
	int path;
	int i;

	i = 0;
	while (i < its->diff[difer]->lenght)
	{
		path = its->diff[difer]->paths[i];
		its->paths[path]->ants = 0;
		i++;
	}
}

static int	getCountStep(t_data *its, int difer)
{
	int path;
	int	i;
	int	turn;
	int	maximum_turns;

	i = 0;
	while (i++ < its->antsIndex)
	{
		path = getBestWay(its, difer);
		its->paths[path]->ants++;
	}
	i = 0;
	maximum_turns = -1;
	while (i < its->diff[difer]->lenght)
	{
		path = its->diff[difer]->paths[i];
		if (its->paths[path]->ants)
		{
			turn = its->paths[path]->ants + its->paths[path]->lenght - 2;
			if (maximum_turns < turn)
				maximum_turns = turn;
		}
		i++;
	}
	return (maximum_turns);
}

static int	getBestDifer(t_data *its)
{
	int	i;
	int	turn;
	int	minimum_turns;
	int	bst;

	minimum_turns = INFIN;
	bst = -1;
	i = 0;
	while (its->diff[i])
	{
		turn = getCountStep(its, i);
		if (turn < minimum_turns)
		{
			minimum_turns = turn;
			bst = i;
		}
		cleanWays(its, i);
		i++;
	}
	return (bst);
}

void		getBestWays(t_data *its, int lst)
{
	t_path	**path;
	int		bst;
	int		i;

	if (lst == 0)
		return ;
	bst = getBestDifer(its);
	path = (t_path **)malloc(sizeof(t_path *) * (its->diff[bst]->lenght + 1));
	i = 0;
	while (i < its->diff[bst]->lenght)
	{
		path[i] = its->paths[its->diff[bst]->paths[i]];
		i++;
	}
	path[i] = NULL;
	i = 0;
	while (its->paths[i])
	{
		its->paths[i]->ants = 0;
		i++;
	}
	its->allWays = its->paths;
	its->paths = path;
}
