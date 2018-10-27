/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeNext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:41:17 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 16:41:59 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	removeTwoNext(t_data *its)
{
	int	index;

	index = 0;
	while (its->diff && its->diff[index])
	{
		free(its->diff[index]->paths);
		free(its->diff[index++]);
	}
	if (its->diff)
		free(its->diff);
}

void	removeNext(t_data *its)
{
	int	index;

	index = 0;
	while (its->mtx && index < its->size)
		free(its->mtx[index++]);
	if (its->mtx)
		free(its->mtx);
	index = 0;
	while (its->allWays && its->allWays[index])
	{
		free(its->allWays[index]->path);
		free(its->allWays[index++]);
	}
	if (its->allWays)
		free(its->allWays);
	if (its->paths)
		free(its->paths);
	index = 0;
	while (its->ants && its->ants[index])
		free(its->ants[index++]);
	if (its->ants)
		free(its->ants);
	removeTwoNext(its);
}
