/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsPutLink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:59:29 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:16 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	horizonLine(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int	y;
	int x;
	int	maximum;

	y = roomOne->crdY;
	if (roomOne->crdX < roomTwo->crdX)
	{
		x = roomOne->crdX + (int)ft_strlen(roomOne->ids) + 1;
		maximum = roomTwo->crdX - 1;
	}
	else if (roomOne->crdX > roomTwo->crdX)
	{
		x = roomTwo->crdX + (int)ft_strlen(roomTwo->ids) + 1;
		maximum = roomOne->crdX - 1;
	}
	else
		return (0);
	while (x < maximum)
	{
		map[y][x] = '-';
		x++;
	}
	return (1);
}

static int	verticLine(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int	y;
	int x;
	int	maximum;

	x = roomOne->crdX;
	if (roomOne->crdY < roomTwo->crdY)
	{
		y = roomOne->crdY + 1;
		maximum = roomTwo->crdY - 1;
	}
	else if (roomOne->crdY > roomTwo->crdY)
	{
		y = roomTwo->crdY + 1;
		maximum = roomOne->crdY - 1;
	}
	else
		return (0);
	while (y <= maximum)
	{
		map[y][x] = '|';
		y++;
	}
	return (1);
}

static int	diagonal(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	int	x;
	int	y;
	int diff;

	y = roomTwo->crdY - roomOne->crdY;
	x = roomTwo->crdX - roomOne->crdX;
	diff = ABS(x) - ABS(y);
	if (ABS(diff) >= 0 && ABS(diff) <= 3)
		return (vsDiagLine(roomOne, roomTwo, map));
	return (0);
}

int			vsPutLink(t_data *its, char **map, t_links *node)
{
	t_rooms	*roomOne;
	t_rooms	*roomTwo;

	roomOne = its->rooms[node->roomFirst];
	roomTwo = its->rooms[node->roomSecond];
	if (roomOne->crdY == roomTwo->crdY)
		return (horizonLine(roomOne, roomTwo, map));
	else if (roomOne->crdX == roomTwo->crdX)
		return (verticLine(roomOne, roomTwo, map));
	else
		return (diagonal(roomOne, roomTwo, map));
}
