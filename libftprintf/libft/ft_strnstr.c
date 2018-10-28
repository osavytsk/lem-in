/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:44:25 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkstr(const char *s1, const char *s2, size_t n)
{
	int		t;

	t = 0;
	while ((s1[t] == s2[t]) && (n > 0) && s1[t])
	{
		t++;
		n--;
	}
	if (s2[t] == '\0')
		return (1);
	return (0);
}

char		*ft_strnstr(const char *s, const char *str, size_t len)
{
	if (!str[0])
		return ((char*)s);
	while (*s && (len > 0))
	{
		if (checkstr(s, str, len) == 1)
			return ((char*)s);
		s++;
		len--;
	}
	return (NULL);
}
