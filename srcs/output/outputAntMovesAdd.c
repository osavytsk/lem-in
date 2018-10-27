/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputAntMovesAdd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:00:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:21:03 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static void	outTwo(t_data *its, int turns, int **antMoves, int i)
{
	int path;
	int	j;
	int	t;

	path = its->ants[i]->path;
	ft_printf("L%-5d| ", its->ants[i]->ids);
	j = 0;
	while (j < turns)
	{
		if (antMoves[i][j] == 0)
			t = antMoves[i][j];
		else
			t = antMoves[i][j] - 1;
		if (t < 0)
			t = its->paths[path]->lenght - 1;
		if (t == 0)
			ft_printf("{green}");
		else if (t == its->paths[path]->lenght - 1)
			ft_printf("{red}");
		ft_printf("%3s%2s{eoc}", its->rooms[its->paths[path]->path[t]]->ids, " ");
		j++;
	}
	ft_printf("\n");
}

void		outputResult(t_data *its, int turns, int **antMoves)
{
	int	i;

	ft_printf("MOVES | ");
	i = 0;
	while (i < turns)
	{
		ft_printf("%3d%2s", i, " ");
		i++;
	}
	ft_printf("\n------|-");
	i = 0;
	while (i < turns)
	{
		ft_printf("%.5s", "----------------------------------------");
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < its->antsIndex)
	{
		outTwo(its, turns, antMoves, i);
		i++;
	}
}
