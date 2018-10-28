/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 01:15:32 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/29 01:27:33 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int			read_begin(t_area *areas, char *s)
{
	char	**array;

	free(s);
	if (!check_area_condition(0, areas))
		return (0);
	if (get_next_line(0, &s) < 1)
		print_error("ERROR : description of start room not found");
	array = ft_strsplit(s, ' ');
	if (!check_area_specific(areas, array) || ft_strstr(s, "  ")
		|| s[ft_strlen(s) - 1] == ' ' || s[0] == ' ')
		print_error("ERROR : invalid description of start room");
	ft_putstr("##start\n");
	areas = setup_area(areas);
	areas->ident = ft_strdup(array[0]);
	areas->coord_x = ft_atoi(array[1]);
	areas->coord_y = ft_atoi(array[2]);
	delete_array(array);
	areas->condition = 0;
	ft_putstr(s);
	ft_putchar('\n');
	free(s);
	return (1);
}

int			read_over(t_area *areas, char *s)
{
	char	**array;

	free(s);
	if (!check_area_condition(2, areas))
		return (0);
	if (get_next_line(0, &s) < 1)
		print_error("ERROR : description of end room not found");
	array = ft_strsplit(s, ' ');
	if (!check_area_specific(areas, array) || ft_strstr(s, "  ")
		|| s[ft_strlen(s) - 1] == ' ' || s[0] == ' ')
		print_error("ERROR : invalid description of end room");
	ft_putstr("##end\n");
	areas = setup_area(areas);
	areas->ident = ft_strdup(array[0]);
	areas->coord_x = ft_atoi(array[1]);
	areas->coord_y = ft_atoi(array[2]);
	delete_array(array);
	areas->condition = 2;
	ft_putstr(s);
	ft_putchar('\n');
	free(s);
	return (1);
}

int			read_area(t_area *areas, char *s)
{
	char	**array;

	array = ft_strsplit(s, ' ');
	if (!check_area_specific(areas, array) || ft_strstr(s, "  ")
		|| s[ft_strlen(s) - 1] == ' ' || s[0] == ' ')
	{
		free(s);
		return (0);
	}
	ft_putstr(s);
	ft_putchar('\n');
	areas = setup_area(areas);
	areas->ident = ft_strdup(array[0]);
	areas->coord_x = ft_atoi(array[1]);
	areas->coord_y = ft_atoi(array[2]);
	delete_array(array);
	areas->condition = 1;
	free(s);
	return (1);
}

int			read_bind(t_area *areas, char *s)
{
	char	**array;

	if (ft_strlen(s) < 3
		|| !(array = check_bind_id(areas, areas, s))
		|| !array[1] || ft_strequ(array[0], array[1]))
		return (0);
	ft_putstr(s);
	ft_putchar('\n');
	set_bind(areas, array[0], array[1]);
	set_bind(areas, array[1], array[0]);
	delete_array(array);
	free(s);
	return (1);
}

void		reading_links(t_area *areas, char *s)
{
	if (ft_strchr(s, '-'))
	{
		if (!read_bind(areas, s))
			return ;
	}
	while (get_next_line(0, &s) > 0)
	{
		if (ft_strchr(s, '-'))
		{
			if (!read_bind(areas, s))
				break ;
		}
		else if (s[0] == '#')
			printing_comm(s);
		else
			break ;
	}
	free(s);
}
