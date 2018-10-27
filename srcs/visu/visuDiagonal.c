/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_diagonal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:58:43 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:13 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	leftDiag(t_crd roomOne, t_crd roomTwo, char **map)
{
	int	x;
	int y;

	x = roomOne.x;
	y = roomOne.y;
	while (x <= roomTwo.x && y <= roomTwo.y)
	{
		if (!vsCheck(y, x, map))
			return (0);
		x++;
		y++;
	}
	if (!vsCheckLeft(y, x, map))
		return (0);
	x = roomOne.x;
	y = roomOne.y;
	while (x <= roomTwo.x && y <= roomTwo.y)
	{
		if (map[y][x] == ' ')
			map[y][x] = '\\';
		x++;
		y++;
	}
	return (1);
}

static int	leftDiagonal(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	t_crd crdOne;
	t_crd crdTwo;

	crdTwo.x = roomTwo->crdX;
	crdTwo.y = roomTwo->crdY;
	crdOne.y = roomOne->crdY + 1;
	crdOne.x = roomOne->crdX + 2;
	if (leftDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x--;
	if (leftDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x--;
	if (leftDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x--;
	if (leftDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.y--;
	crdOne.x += 3;
	if (leftDiag(crdOne, crdTwo, map))
		return (1);
	return (0);
}

static int	rightDiag(t_crd roomOne, t_crd roomTwo, char **map)
{
	int	x;
	int y;

	x = roomOne.x;
	y = roomOne.y;
	while (x >= roomTwo.x && y <= roomTwo.y)
	{
		if (!vsCheck(y, x, map))
			return (0);
		x--;
		y++;
	}
	if (!vsCheckRight(y, x, map))
		return (0);
	x = roomOne.x;
	y = roomOne.y;
	while (x >= roomTwo.x && y <= roomTwo.y)
	{
		if (map[y][x] == ' ')
			map[y][x] = '/';
		x--;
		y++;
	}
	return (1);
}

static int	rightDiagonal(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	t_crd crdOne;
	t_crd crdTwo;

	crdTwo.x = roomTwo->crdX;
	crdTwo.y = roomTwo->crdY;
	crdOne.y = roomOne->crdY + 1;
	crdOne.x = roomOne->crdX - 2;
	if (rightDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x++;
	if (rightDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x++;
	if (rightDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.x++;
	if (rightDiag(crdOne, crdTwo, map))
		return (1);
	crdOne.y--;
	crdOne.x -= 3;
	if (rightDiag(crdOne, crdTwo, map))
		return (1);
	return (0);
}

int			vsDiagLine(t_rooms *roomOne, t_rooms *roomTwo, char **map)
{
	if (roomOne->crdY < roomTwo->crdY)
	{
		if (roomOne->crdX < roomTwo->crdX)
			return (leftDiagonal(roomOne, roomTwo, map));
		else
			return (rightDiagonal(roomOne, roomTwo, map));
	}
	else
	{
		if (roomOne->crdX > roomTwo->crdX)
			return (leftDiagonal(roomTwo, roomOne, map));
		else
			return (rightDiagonal(roomTwo, roomOne, map));
	}
}
