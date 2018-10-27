/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createInfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 03:56:58 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:19:19 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

static char	**cleanInput(char **fl)
{
	char	**saveFile;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (fl && fl[i])
		i++;
	saveFile = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (fl && fl[i])
	{
		if (isCommand(fl[i]) && fl[i + 1])
		{
			saveFile[j++] = fl[i++];
			saveFile[j++] = fl[i++];
		}
		else if (isComment(fl[i]))
			i++;
		else
			saveFile[j++] = fl[i++];
	}
	saveFile[j] = NULL;
	return (saveFile);
}

t_data		*createInfo(char **fl)
{
	t_data	*its;

	its = (t_data *)malloc(sizeof(t_data));
	its->antsIndex = -1;
	its->begin = -1;
	its->over = -1;
	its->rooms = NULL;
	its->diff = NULL;
	its->allWays = NULL;
	its->nodes = NULL;
	its->paths = NULL;
	its->ants = NULL;
	its->mtx = NULL;
	its->input = cleanInput(fl);
	its->putAllWays = 0;
	its->putHide = 0;
	its->putMap = 0;
	its->putMoves = 0;
	its->putWays = 0;
	its->putClean = 0;
	its->putAntMove = 0;
	its->putAnt = 0;
	return (its);
}
