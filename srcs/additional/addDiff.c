/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addDiff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 03:55:41 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:20:13 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static t_diff	*createDiff(int *array, int maxLenght)
{
	t_diff	*diff;
	int		i;

	diff = (t_diff *)malloc(sizeof(t_diff));
	diff->paths = (int *)malloc(sizeof(int) * maxLenght);
	diff->lenght = maxLenght;
	i = 0;
	while (i < diff->lenght)
	{
		diff->paths[i] = array[i];
		i++;
	}
	return (diff);
}

int				addDiff(t_data *its, int *array, int maxLenght)
{
	t_diff	**diff;
	int		i;
	int		lenght;

	lenght = 0;
	while (its->diff && its->diff[lenght])
		lenght++;
	diff = (t_diff **)malloc(sizeof(t_diff *) * (lenght + 2));
	i = 0;
	while (i < lenght)
	{
		diff[i] = its->diff[i];
		i++;
	}
	diff[i] = createDiff(array, maxLenght);
	diff[i + 1] = NULL;
	if (its->diff)
		free(its->diff);
	its->diff = diff;
	return (i);
}
