/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:44:30 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	t;

	i = -1;
	j = 0;
	while (str[j])
		j++;
	while (++i < --j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
	return (str);
}
