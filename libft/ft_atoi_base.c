/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:17:41 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const int base, char nbr)
{
	char	*basement;
	int		i;

	basement = "0123456789ABCDEF";
	i = 0;
	while (basement[i] && i < base)
	{
		if (basement[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, const int base)
{
	unsigned long int	result;
	int					minus;
	size_t				i;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i] && (check_base(base, str[i]) >= 0))
	{
		result = result * base + check_base(base, str[i]);
		i++;
	}
	return ((int)(result * minus));
}
