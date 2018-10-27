/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:18:12 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(long long value, int b, char *result, int *i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (value <= -b || b <= value)
		aux(value / b, b, result, i);
	result[(*i)++] = base[value % b];
}

char		*ft_itoa_base(long long value, int base)
{
	long long	v;
	long long	tmp;
	int			len;
	int			i;
	char		*result;

	if (value == (long long)-9223372036854775808LLU)
		return (ft_strdup("-9223372036854775808"));
	tmp = value;
	len = 1;
	while ((tmp /= base))
		len++;
	v = value;
	if (v < 0)
	{
		len = base == 10 ? len + 1 : len;
		v = -v;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (value < 0 && base == 10)
		result[i++] = '-';
	aux(v, base, result, &i);
	result[i] = '\0';
	return (result);
}
