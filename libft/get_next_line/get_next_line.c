/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:24:52 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_lines	*begin_list;

	if (read(fd, NULL, 0) < 0)
		return (-1);
	if (!gnl_createfd(&begin_list, fd))
	{
		*line = NULL;
		return (0);
	}
	*line = gnl_get_line(fd, &begin_list);
	if (*line)
		return (1);
	else
		return (0);
}
