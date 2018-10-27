/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findAllPaths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 01:00:54 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:15:54 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	check(int *array, int i, int room)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (room == array[j])
			return (0);
		j++;
	}
	return (1);
}

static void	recursion(t_data *its, int *array, int i, int room)
{
	int	j;

	array[i] = room;
	if (room == its->over)
	{
		addWay(its, array, i + 1);
		return ;
	}
	j = 0;
	while (j < its->size)
	{
		if (its->mtx[j][room] && check(array, i, j))
			recursion(its, array, i + 1, j);
		j++;
	}
}

static void	findStrPath(t_data *its)
{
	int	j;
	int	i;

	i = 0;
	while (its->paths[i])
	{
		if (its->paths[i]->lenght == 2)
		{
			j = 0;
			while (its->paths[j])
			{
				if (i != j)
				{
					free(its->paths[j]->path);
					free(its->paths[j]);
				}
				j++;
			}
			its->paths[0] = its->paths[i];
			its->paths[1] = NULL;
			break ;
		}
		i++;
	}
}

int			findAllPaths(t_data *its, int lst)
{
	int	i;
	int	*array;

	if (lst == 0 || its->over == -1 || its->begin == -1)
		return (0);
	i = 0;
	while (its->rooms[i])
		i++;
	array = (int *)malloc(sizeof(int) * i);
	buildMatrix(its);
	recursion(its, array, 0, its->begin);
	free(array);
	if (its->paths == NULL)
		return (0);
	findStrPath(its);
	return (lst);
}
