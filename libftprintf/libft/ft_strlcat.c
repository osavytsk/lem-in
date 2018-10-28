/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:43:38 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	i;
	size_t	len;
	size_t	j;
	size_t	d;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	d = s - i - 1;
	if (i < s)
	{
		while (src[j] && (d > 0))
		{
			dst[i] = src[j];
			i++;
			j++;
			d--;
		}
		dst[i] = '\0';
		return (len);
	}
	return (s + ft_strlen(src));
}
