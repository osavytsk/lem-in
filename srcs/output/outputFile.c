/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputFile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 04:21:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

void	outputFile(t_data *its, char **fl, int lstLine)
{
	int	i;

	i = 0;
	if (lstLine == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	while (fl[i])
	{
		if (isComment(fl[i]))
			lstLine++;
		if (!its->putHide && (!its->putClean
					|| !isComment(fl[i])) && i < lstLine)
			ft_printf("%s\n", fl[i]);
		free(fl[i]);
		i++;
	}
	if (!its->putHide)
		ft_printf("\n");
	free(fl);
}
