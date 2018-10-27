/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_diagonal_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:01:14 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static int	check(int y, int x, char **map)
{
	if (map[y][x] != ' ' && map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int			vsCheck(int y, int x, char **map)
{
	if (map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int			vsCheckLeft(int y, int x, char **map)
{
	if (check(y, x, map))
		return (1);
	y--;
	if (check(y, x, map))
		return (1);
	y++;
	x--;
	if (check(y, x, map))
		return (1);
	return (0);
}

int			vsCheckRight(int y, int x, char **map)
{
	if (check(y, x, map))
		return (1);
	y--;
	if (check(y, x, map))
		return (1);
	y++;
	x++;
	if (check(y, x, map))
		return (1);
	return (0);
}
