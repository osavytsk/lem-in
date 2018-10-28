/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:43:04 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
	str1[i] = '\0';
	return (str1);
}
