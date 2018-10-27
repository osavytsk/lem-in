/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addCommand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 03:55:23 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:46:35 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

int		addCommand(t_data *its, int i, int room)
{
	if (ft_strequ(its->input[i - 1], "##start"))
	{
		if (its->begin != -1)
			return (0);
		its->begin = room;
		return (1);
	}
	else if (ft_strequ(its->input[i - 1], "##end"))
	{
		if (its->over != -1)
			return (0);
		its->over = room;
		return (1);
	}
	return (0);
}
