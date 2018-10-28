/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 21:03:10 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:27 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			inspect_ants(char *s)
{
	int		num_ants;

	num_ants = -1;
	while (get_next_line(0, &s) > 0)
	{
		if (s[0] == '\0')
			print_error("ERROR : empty line");
		else if (ft_strequ(s, "##start") || ft_strequ(s, "##end"))
			print_error("ERROR : no number of ants");
		else if (s[0] == '#')
			printing_comm(s);
		else
		{
			num_ants = quantity_of_ants(s);
			break ;
		}
	}
	if (num_ants == -1)
		print_error("ERROR : invalid file");
	ft_putstr(s);
	ft_putchar('\n');
	return (num_ants);
}

void		remove_data(t_area *area, t_area *areas, t_binds **way)
{
	int		i;

	i = -1;
	while (areas)
	{
		area = areas;
		areas = areas->nxt_area;
		dlt_area(area);
	}
	while (way[++i])
	{
		while (way[i]->nxt)
		{
			delete_way(way[i]);
		}
		free(way[i]);
	}
	free(way);
}

void		inspect_data(t_area *areas, char *s)
{
	while (get_next_line(0, &s) > 0)
	{
		if (s[0] == '\0')
			print_error("ERROR : empty line");
		if (ft_strequ(s, "##start"))
		{
			if (!read_begin(areas, s))
				break ;
		}
		else if (ft_strequ(s, "##end"))
		{
			if (!read_over(areas, s))
				break ;
		}
		else if (s[0] == '#')
			printing_comm(s);
		else if (is_area(s))
		{
			if (!read_area(areas, s))
				break ;
		}
		else
			break ;
	}
	reading_links(areas, s);
}

int			main(void)
{
	t_area	*areas;
	t_binds	**path;
	int		num_ants;
	char	*s;

	s = NULL;
	areas = setup_areas();
	num_ants = inspect_ants(s);
	inspect_data(areas, s);
	if (check_area_condition(0, areas) || check_area_condition(2, areas))
		print_error("ERROR : no start or end room");
	path = find_path(get_area(areas->nxt_area, 0),
					 areas->nxt_area, num_ants < 100 ? num_ants : 100);
	set_intent(areas->nxt_area);
	if (!path[0]->nxt)
		print_error("ERROR : any path not found");
	ft_putchar('\n');
	ants_in_action(0, path, num_ants);
	remove_data(areas, areas, path);
	return (0);
}
