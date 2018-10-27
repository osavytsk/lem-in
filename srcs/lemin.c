/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 21:49:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:50:51 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main(void)
{
	t_data	*data;
	char	**fl;
	int		lastLine;

	fl = readFile();
	data = createInfo(fl);
	lastLine = parseInput(data);
	lastLine = findAllPaths(data, lastLine);
	searchDiff(data, lastLine);
	getBestWays(data, lastLine);
	parseCom(data, lastLine, fl);
	createAnts(data, lastLine);
	outputResults(data, lastLine, fl);
	removeAll(data);
//	sleep(5);
	return (0);
}
