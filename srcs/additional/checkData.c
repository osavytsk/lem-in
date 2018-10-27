/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkData.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:56:39 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:48:31 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

int		isCommand(char *s)
{
	if (ft_strequ(s, "##start") || ft_strequ(s, "##end"))
		return (1);
	return (0);
}

int		isComment(char *s)
{
	if (s[0] == '#' && !isCommand(s))
		return (1);
	return (0);
}

int		isInt(char *s)
{
	unsigned int	res;
	int				mns;
	size_t			i;

	i = 0;
	mns = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
			|| s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-')
		mns = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	res = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		res = res * 10 + (s[i] - 48);
		if (res >= 2147483648 || (res > 2147483648 && mns))
			return (0);
		i++;
	}
	return (1);
}

int		roomExists(t_data *its, char **array)
{
	int		i;
	char	*ids;
	int		x;
	int		y;

	if (its->rooms == NULL)
		return (0);
	ids = array[0];
	x = ft_atoi(array[1]);
	y = ft_atoi(array[2]);
	i = 0;
	while (its->rooms[i])
	{
		if (ft_strequ(ids, its->rooms[i]->ids))
			return (1);
		if (x == its->rooms[i]->crdX && y == its->rooms[i]->crdY)
			return (1);
		i++;
	}
	return (0);
}
