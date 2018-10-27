/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseCom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:29:24 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:14:17 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static void	addComm(t_data *its, char *s)
{
	if (ft_strequ(s, "##map"))
		its->putMap = 1;
	else if (ft_strequ(s, "##moves"))
		its->putMoves = 1;
	else if (ft_strequ(s, "##allways"))
		its->putAllWays = 1;
	else if (ft_strequ(s, "##paths"))
		its->putWays = 1;
	else if (ft_strequ(s, "##hide"))
		its->putHide = 1;
	else if (ft_strequ(s, "##clean"))
		its->putClean = 1;
	else if (ft_strequ(s, "##antmoves"))
		its->putAntMove = 1;
	else if (ft_strequ(s, "##ants"))
		its->putAnt = 1;
}

void		parseCom(t_data *its, int lstLine, char **fl)
{
	int	i;

	if (lstLine == 0)
		return ;
	i = 0;
	while (fl[i])
	{
		if (isComment(fl[i]))
		{
			addComm(its, fl[i]);
			lstLine++;
		}
		if (i >= lstLine)
			return ;
		i++;
	}
}
