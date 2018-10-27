/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:22:12 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int max_len)
{
	char	*result;
	int		str_len;
	int		i;

	if (max_len < 0)
		return (str);
	str_len = (int)ft_strlen(str);
	if (str_len < max_len)
		max_len = (int)str_len;
	result = (char *)malloc(sizeof(char) * (max_len + 1));
	i = 0;
	while (i < max_len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}
