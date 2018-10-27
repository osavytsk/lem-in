/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readFile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 03:57:07 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:48:28 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lemin.h"

char	**readFile(void)
{
	char	**saveFl;
	char	*fl;

	fl = ft_readfd(FD);
	saveFl = ft_strsplit(fl, '\n');
	free(fl);
	return (saveFl);
}
