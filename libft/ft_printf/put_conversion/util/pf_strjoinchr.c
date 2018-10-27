/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strjoinchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:27:24 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_util.h"

char	*pf_strjoinchr(char *str, char const chr, int count,
		t_position position)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + count + 1));
	if (!result)
		return (0);
	j = 0;
	if (position == BEGIN)
	{
		while ((count--) > 0)
			result[j++] = chr;
	}
	i = 0;
	while (str[i])
		result[j++] = str[i++];
	while ((count--) > 0)
		result[j++] = chr;
	result[j] = '\0';
	free(str);
	return (result);
}
