/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addWay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:56:13 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:19:42 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	putWay(t_data *its, int *newPath, int distance)
{
	t_path	**paths;
	int		i;
	int		lenght;

	lenght = 0;
	while (its->paths && its->paths[lenght])
		lenght++;
	paths = (t_path **)malloc(sizeof(t_path *) * (lenght + 2));
	i = 0;
	while (i < lenght)
	{
		paths[i] = its->paths[i];
		i++;
	}
	paths[i] = (t_path *)malloc(sizeof(t_path));
	paths[i]->path = newPath;
	paths[i]->lenght = distance;
	paths[i]->ants = 0;
	paths[i + 1] = NULL;
	if (its->paths)
		free(its->paths);
	its->paths = paths;
	return (i);
}

int			addWay(t_data *its, int *path, int lenght)
{
	int *newPath;
	int	i;

	newPath = (int *)malloc(sizeof(int) * (lenght));
	i = 0;
	while (i < lenght)
	{
		newPath[i] = path[i];
		i++;
	}
	return (putWay(its, newPath, lenght));
}
