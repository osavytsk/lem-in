/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:42:21 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	n1;
	long	nb;

	i = 1;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(nb / i + '0', fd);
		nb %= i;
		i /= 10;
	}
}
