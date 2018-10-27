/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputPaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 01:04:34 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static void	outAntsEoc(t_path *path, t_data *its)
{
	if (path->ants && its->putAnt)
		ft_printf("{yellow} | ANTS: %d{eoc}\n", path->ants);
	else
		ft_printf("{eoc}\n");
}

void		outputPaths(t_data *its)
{
	int	j;
	int	i;

	i = 0;
	ft_printf("{red}SELECTED WAYS:{eoc}\n");
	while (its->paths && its->paths[i])
	{
		if (its->paths[i]->ants)
			ft_printf("{green}");
		else
			ft_printf("{red}");
		ft_printf("%d: ", i + 1);
		j = 0;
		while (j < its->paths[i]->lenght)
		{
			if (j > 0)
				ft_printf("->");
			ft_printf("%s", its->rooms[its->paths[i]->path[j]]->ids);
			j++;
		}
		outAntsEoc(its->paths[i], its);
		i++;
	}
	ft_printf("\n");
}
