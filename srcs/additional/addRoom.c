/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addRoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 00:56:04 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:20:32 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

int		addRoom(t_data *its, char **array)
{
	t_rooms	**rooms;
	int		i;
	int		lenght;

	lenght = 0;
	while (its->rooms && its->rooms[lenght])
		lenght++;
	rooms = (t_rooms **)malloc(sizeof(t_rooms *) * (lenght + 2));
	i = 0;
	while (i < lenght)
	{
		rooms[i] = its->rooms[i];
		i++;
	}
	rooms[i] = (t_rooms *)malloc(sizeof(t_rooms));
	rooms[i]->ids = ft_strdup(array[0]);
	rooms[i]->crdX = ft_atoi(array[1]);
	rooms[i]->crdY = ft_atoi(array[2]);
	rooms[i + 1] = NULL;
	if (its->rooms)
		free(its->rooms);
	its->rooms = rooms;
	return (i);
}
