/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_binds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:45:59 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:47 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char		**array_init(void)
{
	char	**array;

	if (!(array = (char**)malloc(sizeof(char*) * 3)))
		return (NULL);
	array[0] = NULL;
	array[1] = NULL;
	array[2] = NULL;
	return (array);
}

void		check_second_area(t_area *area, char *ptr, char **array)
{
	while (area->nxt_area != NULL)
	{
		area = area->nxt_area;
		if (ft_strequ(area->ident, ptr))
		{
			array[1] = ft_strdup(ptr);
			break ;
		}
	}
}

char		**check_bind_id(t_area *begin, t_area *area, char *s)
{
	char	**array;
	char	*ptr;

	array = array_init();
	ptr = NULL;
	while (begin->nxt_area != NULL)
	{
		begin = begin->nxt_area;
		if (!ft_strncmp(begin->ident, s, ft_strlen(begin->ident))
			&& s[ft_strlen(begin->ident)] == '-')
		{
			array[0] = ft_strnew(ft_strlen(begin->ident));
			ft_strncpy(array[0], s, ft_strlen(begin->ident));
			ptr = &s[ft_strlen(begin->ident)];
			break ;
		}
	}
	if (!array[0] || !ptr || *ptr != '-')
		return (NULL);
	ptr++;
	check_second_area(area, ptr, array);
	return (array);
}

t_area		*setup_areas(void)
{
	t_area	*areas;

	areas = malloc(sizeof(t_area));
	areas->nxt_area = NULL;
	areas->ident = NULL;
	areas->binds = NULL;
	areas->intent = -1;
	areas->condition = -1;
	areas->coord_x = -1;
	areas->coord_y = -1;
	return (areas);
}
