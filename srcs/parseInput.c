/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseInput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:20:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:14:13 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	getRoom(t_data *its, char *ids)
{
	int	i;

	if (its->rooms == NULL)
		return (-1);
	i = 0;
	while (its->rooms[i])
	{
		if (ft_strequ(its->rooms[i]->ids, ids))
			return (i);
		i++;
	}
	return (-1);
}

static int	parseLink(t_data *its, int i)
{
	int		roomFirst;
	int		roomSecond;
	int		index;
	char	**array;

	array = ft_strsplit(its->input[i], '-');
	index = 0;
	while (array[index])
		index++;
	if (index != 2)
	{
		ft_arrdel(array);
		return (0);
	}
	roomFirst = getRoom(its, array[0]);
	roomSecond = getRoom(its, array[1]);
	ft_arrdel(array);
	if (roomFirst < 0 || roomSecond < 0)
		return (0);
	if (roomFirst != roomSecond)
		addLink(its, roomFirst, roomSecond);
	return (1);
}

static int	parseRoom(t_data *its, int i)
{
	int		room;
	int		index;
	char	**array;

	array = ft_strsplit(its->input[i], ' ');
	index = 0;
	while (array[index])
		index++;
	if (index != 3 || array[0][0] == 'L' || ft_strcchr(array[0], '-')
		|| !isInt(array[1]) || !isInt(array[2]) || roomExists(its, array))
	{
		ft_arrdel(array);
		return (0);
	}
	room = addRoom(its, array);
	ft_arrdel(array);
	if (isCommand(its->input[i - 1]))
		return (addCommand(its, i, room));
	return (1);
}

static int	parseAnt(t_data *its)
{
	if (its->input[0])
		its->antsIndex = ft_atoi(its->input[0]);
	if (its->antsIndex <= 0 || !isInt(its->input[0]))
		return (0);
	return (1);
}

int			parseInput(t_data *its)
{
	int	comm;
	int	i;

	if (!(i = parseAnt(its)))
		return (0);
	if (isCommand(its->input[i]))
		i++;
	comm = 1;
	while (its->input[i] && parseRoom(its, i))
	{
		i++;
		comm = 0;
		if (isCommand(its->input[i]))
		{
			i++;
			comm = 1;
		}
	}
	if (comm)
		return (i);
	while (its->input[i] && parseLink(its, i))
		i++;
	return (i);
}
