/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:44:35 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *string, const char *str)
{
	int	i;
	int	f;
	int	l;

	i = 0;
	if (!str[0])
		return ((char*)string);
	while (string[i])
	{
		f = i;
		l = 0;
		while (string[f] == str[l])
		{
			f++;
			l++;
			if (str[l] == '\0')
				return ((char*)&string[i]);
		}
		i++;
	}
	return (NULL);
}
