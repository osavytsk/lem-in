/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:15:46 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:50 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			simply_number(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			quantity_of_ants(char *s)
{
	int		result;

	if (!simply_number(s))
		print_error("ERROR : number of ants is invalid value");
	if (ft_strlen(s) > 10 || (ft_strlen(s) == 10 && s[0] > '2'))
		print_error("ERROR : I do not hold as many ants");
	result = ft_atoi(s);
	free(s);
	if (result < 1)
		print_error("ERROR : number of ants should only be positive integer");
	return (result);
}

t_area		*search_elem(t_area *area, char *ident)
{
	while (area->nxt_area)
	{
		area = area->nxt_area;
		if (ft_strequ(area->ident, ident))
			break ;
	}
	return (area);
}

void		set_bind(t_area *area, char *from, char *in)
{
	t_area	*ptr;
	t_binds	*bind_one;
	t_binds	*bind_two;

	ptr = search_elem(area, in);
	area = search_elem(area, from);
	if (!area->binds)
	{
		area->binds = malloc(sizeof(t_binds));
		area->binds->bind = ptr;
		area->binds->nxt = NULL;
	}
	else
	{
		bind_two = area->binds;
		while (bind_two->nxt)
			bind_two = bind_two->nxt;
		bind_one = malloc(sizeof(t_binds));
		bind_one->bind = ptr;
		bind_one->nxt = NULL;
		bind_two->nxt = bind_one;
	}
}

void		printing_comm(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	free(s);
}
