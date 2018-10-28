/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 22:37:33 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:21 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		print_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void		delete_array(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array[i]);
	free(array);
}

void		dlt_area(t_area *area)
{
	t_binds	*bind;

	if (area->ident != NULL)
		free(area->ident);
	while (area->binds)
	{
		bind = area->binds;
		area->binds = area->binds->nxt;
		free(bind);
	}
	free(area);
}
