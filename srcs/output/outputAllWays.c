/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputAllPaths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:04:03 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static void	sortAllPaths(t_path **paths)
{
	size_t	i;
	size_t	j;
	size_t	lenght;
	t_path	*temp;

	lenght = 0;
	while (paths[lenght])
		lenght++;
	i = 0;
	while (i < (lenght - 1))
	{
		j = 0;
		while (j < (lenght - i - 1))
		{
			if (paths[j]->lenght > paths[j + 1]->lenght)
			{
				temp = paths[j];
				paths[j] = paths[j + 1];
				paths[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	outAntsColor(t_path *path, t_data *its)
{
	if (path->ants && its->putAnt)
		ft_printf("{yellow} | ANTS: %d{eoc}\n", path->ants);
	else
		ft_printf("{eoc}\n");
}

void		outputAllPaths(t_data *its)
{
	int	j;
	int	i;

	i = 0;
	sortAllPaths(its->allWays);
	ft_printf("{red}ALL WAYS:{eoc}\n");
	while (its->allWays && its->allWays[i])
	{
		if (its->allWays[i]->ants)
			ft_printf("{green}");
		else
			ft_printf("{red}");
		ft_printf("%d: ", i + 1);
		j = 0;
		while (j < its->allWays[i]->lenght)
		{
			if (j > 0)
				ft_printf("->");
			ft_printf("%s", its->rooms[its->allWays[i]->path[j]]->ids);
			j++;
		}
		outAntsColor(its->allWays[i], its);
		i++;
	}
	ft_printf("\n");
}
