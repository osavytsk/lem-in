/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_add_diagonal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:58:17 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:03:33 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

int	vsRdd(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int j;

	j = roomOne->crdY + 1;
	while (j < roomTwo->crdY)
	{
		map[j][i] = '\\';
		i++;
		j++;
	}
	return (i);
}

int	vsRud(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int j;

	j = roomOne->crdY - 1;
	while (j > roomTwo->crdY)
	{
		map[j][i] = '/';
		i++;
		j--;
	}
	return (i);
}

int	vsLdd(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int j;

	j = roomOne->crdY + 1;
	while (j < roomTwo->crdY)
	{
		map[j][i] = '/';
		i--;
		j++;
	}
	return (i);
}

int	vsLud(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int j;

	j = roomOne->crdY - 1;
	while (j > roomTwo->crdY)
	{
		map[j][i] = '\\';
		i--;
		j--;
	}
	return (i);
}
