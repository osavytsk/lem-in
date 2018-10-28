/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:41:20 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_count(long v)
{
	size_t		r;

	r = 0;
	if (v == 0)
		r++;
	if (v < 0)
	{
		r++;
		v = -v;
	}
	while (v > 0)
	{
		r++;
		v /= 10;
	}
	return (r);
}

static char		*ft_print_str(char *s, long nb, int i)
{
	int			j;
	long		n;

	j = 0;
	if (nb < 0)
	{
		s[j++] = '-';
		nb = -nb;
	}
	n = nb;
	while ((n / 10) > 0)
	{
		i *= 10;
		n /= 10;
	}
	while (i > 0)
	{
		s[j++] = (nb / i) + '0';
		nb %= i;
		i /= 10;
	}
	s[j] = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char		*res;

	if ((res = ft_strnew(str_count((long)n))) == NULL)
		return (NULL);
	return (ft_print_str(res, (long)n, 1));
}
