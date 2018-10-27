/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:59:20 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:14 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	rightHoriz(int x, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int diff;
	int x1;
	int	y;

	diff = 100;
	while (ABS(diff) < 0 || ABS(diff) > 2)
	{
		y = roomTwo->crdY - roomOne->crdY;
		x1 = roomTwo->crdX - x;
		diff = ABS(x1) - ABS(y);
		map[roomOne->crdY][x] = '-';
		x++;
	}
	map[roomOne->crdY][x++] = '-';
	map[roomOne->crdY][x++] = '-';
	return (x);
}

static int	leftHoriz(int x, t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int diff;
	int x1;
	int	y;

	diff = 100;
	while (ABS(diff) < 0 || ABS(diff) > 2)
	{
		y = roomTwo->crdY - roomOne->crdY;
		x1 = roomTwo->crdX - x;
		diff = ABS(x1) - ABS(y);
		map[roomOne->crdY][x] = '-';
		x--;
	}
	map[roomOne->crdY][x--] = '-';
	map[roomOne->crdY][x--] = '-';
	return (x);
}

static void	putLineOne(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int	y;
	int	x;

	x = roomOne->crdX + 2;
	y = roomOne->crdY;
	if (map[y][x] == ' ')
	{
		x = rightHoriz(x, roomOne, roomTwo, map);
		if (roomOne->crdY < roomTwo->crdY)
			vsRdd(x, roomOne, roomTwo, map);
		else
			vsRud(x, roomOne, roomTwo, map);
		return ;
	}
	x = roomTwo->crdX - 2;
	y = roomTwo->crdY;
	if (map[y][x] == ' ')
	{
		x = leftHoriz(x, roomTwo, roomOne, map);
		if (roomTwo->crdY < roomOne->crdY)
			vsLdd(x, roomTwo, roomOne, map);
		else
			vsLud(x, roomTwo, roomOne, map);
		return ;
	}
}

static void	putLineTwo(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int	y;
	int	x;

	x = roomOne->crdX - 2;
	y = roomOne->crdY;
	if (map[y][x] == ' ')
	{
		x = leftHoriz(x, roomOne, roomTwo, map);
		if (roomOne->crdY < roomTwo->crdY)
			vsLdd(x, roomOne, roomTwo, map);
		else
			vsLud(x, roomOne, roomTwo, map);
		return ;
	}
	x = roomTwo->crdX + 2;
	y = roomTwo->crdY;
	if (map[y][x] == ' ')
	{
		x = rightHoriz(x, roomTwo, roomOne, map);
		if (roomTwo->crdY < roomOne->crdY)
			vsRdd(x, roomTwo, roomOne, map);
		else
			vsRud(x, roomTwo, roomOne, map);
		return ;
	}
}

void		vsAddLines(int *nodes, t_data *its, char **map)
{
	int		i;
	t_rooms	*roomOne;
	t_rooms	*roomTwo;

	i = 0;
	while (its->nodes[i])
	{
		roomOne = its->rooms[its->nodes[i]->roomFirst];
		roomTwo = its->rooms[its->nodes[i]->roomSecond];
		if (nodes[i] == 0)
		{
			if (roomOne->crdX < roomTwo->crdX)
				putLineOne(roomOne, roomTwo, map);
			else
				putLineTwo(roomOne, roomTwo, map);
		}
		i++;
	}
	free(nodes);
}
