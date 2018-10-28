/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_area.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 10:41:12 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:41 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_area		*setup_area(t_area *area)
{
	t_area	*ptr;

	while (area->nxt_area != NULL)
		area = area->nxt_area;
	ptr = malloc(sizeof(t_area));
	ptr->ident = NULL;
	ptr->condition = -1;
	ptr->binds = NULL;
	ptr->nxt_area = NULL;
	ptr->intent = 0;
	area->nxt_area = ptr;
	return (ptr);
}

int			is_area(char *s)
{
	char **array;

	array = ft_strsplit(s, ' ');
	if (array[0] && array[1] && array[2])
	{
		delete_array(array);
		return (1);
	}
	else
	{
		delete_array(array);
		return (0);
	}
}
