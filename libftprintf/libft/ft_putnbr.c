/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:42:18 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	int		i;
	long	n1;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	n1 = nb;
	while (n1 / 10 > 0)
	{
		i *= 10;
		n1 /= 10;
	}
	while (i > 0)
	{
		ft_putchar(nb / i + '0');
		nb %= i;
		i /= 10;
	}
}
