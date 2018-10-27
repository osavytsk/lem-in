/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsPutMap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 00:59:59 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:03:41 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static char	**addMap(void)
{
	char	**map;
	int		x;
	int		y;

	map = (char **)malloc(sizeof(char *) * MAP_SZ);
	x = 0;
	while (x < MAP_SZ)
	{
		map[x] = (char *)malloc(sizeof(char) * (MAP_SZ + 1));
		y = 0;
		while (y < MAP_SZ)
		{
			map[x][y] = ' ';
			y++;
		}
		map[x][y] = '\0';
		x++;
	}
	return (map);
}

static int	getMaxLine(char **map)
{
	int	y;
	int x;
	int	maximum;

	maximum = 0;
	x = 0;
	while (x < MAP_SZ)
	{
		y = 0;
		while (y < MAP_SZ)
		{
			if (map[x][y] != ' ')
				maximum = x;
			y++;
		}
		x++;
	}
	return (maximum);
}

static void	printMap(char **map)
{
	int	maximum;
	int	i;

	maximum = getMaxLine(map);
	i = 0;
	while (i < MAP_SZ)
	{
		if (i <= maximum)
			ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	ft_printf("\n");
	free(map);
}

static void	putRoom(char **map, t_rooms *room)
{
	int	i;
	int	x;
	int	y;

	x = room->crdX;
	y = room->crdY;
	map[y][x - 1] = '[';
	i = 0;
	while (room->ids[i])
	{
		if (x + i < MAP_SZ)
			map[y][x + i] = room->ids[i];
		i++;
	}
	if (x + i < MAP_SZ)
		map[y][x + i] = ']';
}

void		vsPutMap(t_data *its)
{
	int		*nodes;
	char	**map;
	int		i;

	map = addMap();
	i = 0;
	while (its->rooms[i])
		putRoom(map, its->rooms[i++]);
	i = 0;
	while (its->nodes[i])
		i++;
	nodes = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (its->nodes[i])
	{
		nodes[i] = vsPutLink(its, map, its->nodes[i]);
		i++;
	}
	vsAddLines(nodes, its, map);
	printMap(map);
}
