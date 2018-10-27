/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createAnts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:29:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:03 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	getBestPath(t_data *its)
{
	int bst;
	int	minimum;
	int	i;

	i = 0;
	bst = i;
	minimum = its->paths[i]->lenght + its->paths[i]->ants;
	while (its->paths[i])
	{
		if (minimum > (its->paths[i]->lenght + its->paths[i]->ants))
		{
			bst = i;
			minimum = its->paths[i]->lenght + its->paths[i]->ants;
		}
		i++;
	}
	return (bst);
}

static void	getAnts(t_data *its)
{
	int	i;
	int	j;

	its->ants = (t_ants **)malloc(sizeof(t_ants *) * (its->antsIndex + 1));
	i = 0;
	while (i < its->antsIndex)
	{
		j = 0;
		while (its->paths[j])
		{
			if (its->paths[j]->ants > 0 && i < its->antsIndex)
			{
				its->ants[i] = (t_ants *)malloc(sizeof(t_ants));
				its->ants[i]->turn = 1;
				its->ants[i]->ids = i + 1;
				its->ants[i]->path = j;
				its->paths[j]->ants--;
				i++;
			}
			j++;
		}
	}
	its->ants[i] = NULL;
}

void		createAnts(t_data *its, int lst)
{
	int	i;

	if (lst == 0)
		return ;
	i = 0;
	while (i++ < its->antsIndex)
		its->paths[getBestPath(its)]->ants++;
	getAnts(its);
	i = 0;
	while (its->paths[i])
	{
		its->paths[i]->ants = 0;
		i++;
	}
	i = 0;
	while (i++ < its->antsIndex)
		its->paths[getBestPath(its)]->ants++;
}
