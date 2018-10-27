/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchDiff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 23:29:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:12:56 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	isParal(t_data *d, int p1, int p2)
{
	int i;
	int	j;
	int	t;

	i = 0;
	while (i < d->paths[p1]->lenght)
	{
		j = 0;
		while (j < d->paths[p2]->lenght)
		{
			t = d->paths[p1]->path[i];
			if (t == d->paths[p2]->path[j] && t != d->over && t != d->begin)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	isParalWays(t_data *its, int *array, int lenght, int path)
{
	int i;

	i = 0;
	while (i < lenght)
	{
		if (array[i] == path || !isParal(its, array[i], path))
			return (0);
		i++;
	}
	return (1);
}

static void	recursion(t_data *its, int *array, int lenght, int path)
{
	int	bin;
	int	i;

	array[lenght++] = path;
	bin = 1;
	i = 0;
	while (its->paths[i])
	{
		if (isParalWays(its, array, lenght, i))
		{
			recursion(its, array, lenght, i);
			bin = 0;
		}
		i++;
	}
	if (bin)
        addDiff(its, array, lenght);
}

void		searchDiff(t_data *its, int lst)
{
	int	path;
	int	*array;

	if (lst == 0)
		return ;
	path = 0;
	while (its->paths[path])
		path++;
	array = (int *)malloc(sizeof(int) * path);
	path = 0;
	while (its->paths[path])
	{
		recursion(its, array, 0, path);
		path++;
	}
	free(array);
}
