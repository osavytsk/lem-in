/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_zerocut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:27:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_util.h"

char	*pf_zerocut(char *nbr)
{
	int	i;

	i = (int)ft_strlen(nbr) - 1;
	while (i >= 0)
	{
		if (nbr[i] != '0')
			break ;
		i--;
	}
	return (ft_strcut(nbr, i + 1));
}
