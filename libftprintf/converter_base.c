/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:39:57 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:44:58 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft(unsigned long long v, unsigned long long b, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (v >= b)
		ft(v / b, b, str, i);
	str[(*i)++] = tmp[(v % b)];
}

char		*ft_unsigned_atol(unsigned long long value, unsigned long long base)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	ft(value, base, str, &i);
	return (str);
}

static void	funct(long long v, long long b, char *str, int *i)
{
	char	*tmp;

	tmp = "0123456789abcdef";
	if (v <= -b || v >= b)
		funct(v / b, b, str, i);
	str[(*i)++] = tmp[(v % b) < 0 ? -(v % b) : (v % b)];
}

char		*ft_atol_base(long long value, long long base)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(32);
	funct(value, base, str, &i);
	return (str);
}

char		*ft_dtoa_base(double value, int base, int i)
{
	char	*str;
	char	*p;
	float	val;

	str = ft_atol_base((long long)value, (long long)base);
	while (str[i])
		i++;
	str[i] = '.';
	p = str;
	val = value - (long)value;
	if (val == 1)
	{
		free(p);
		str = ft_atol_base((long long)value + 1, (long long)base);
		while (str[i])
			i++;
		str[i] = '.';
	}
	else
	{
		val = (int)(val * 1000000);
		str = ft_strjoin(p, ft_atol_base((long long)val, (long long)base));
		free(p);
	}
	return (str);
}
