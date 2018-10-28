/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reloc_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:08 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:36 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		crosscut(t_binds *way, int num_ants)
{
	int		i;

	i = 0;
	while (num_ants-- > 0)
		ft_printf("L%d-%s ", ++i, way->nxt->bind->ident);
	ft_putchar('\n');
}

void		contin_relocation(t_binds **way, int num_ants, int *finish, int n)
{
	while (way[++n] && way[n]->nxt
		&& num_ants < way_length(way[n]) - way_length(way[0]))
		relocation(way[n], finish);
}

void		ants_anoth_paths(t_binds **way, int *nants, int *finish, int *i)
{
	int		j;

	j = 0;
	while (way[++j] && way[j]->nxt
		&& *nants >= way_length(way[j]) - way_length(way[0]) && (*nants)-- > 0)
	{
		(*i)++;
		way[j]->bind->intent = *i;
		relocation(way[j], finish);
	}
	contin_relocation(way, *nants, finish, j - 1);
}

void		relocation(t_binds *way, int *finish)
{
	if (!way->nxt)
		return ;
	relocation(way->nxt, finish);
	if (way->bind->intent)
	{
		way->nxt->bind->intent = way->bind->intent;
		ft_printf("L%d-%s ", way->bind->intent, way->nxt->bind->ident);
		way->bind->intent = 0;
		if (way->nxt->bind->condition == 2)
			(*finish)--;
	}
}

void		ants_in_action(int i, t_binds **way, int nants)
{
	int		j;
	int		finish;

	finish = nants;
	if (way[0]->nxt->bind->condition == 2)
		return (crosscut(way[0], nants));
	while (nants-- > 0)
	{
		i++;
		way[0]->bind->intent = i;
		relocation(way[0], &finish);
		if (way[1] && way[1]->nxt
			&& nants >= way_length(way[1]) - way_length(way[0]) && nants > 0)
			ants_anoth_paths(way, &nants, &finish, &i);
		else
			contin_relocation(way, nants, &finish, 0);
		ft_putchar('\n');
	}
	while (finish)
	{
		j = -1;
		while (way[++j] && way[j]->nxt)
			relocation(way[j], &finish);
		ft_putchar('\n');
	}
}
