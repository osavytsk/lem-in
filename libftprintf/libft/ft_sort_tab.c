/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:42:36 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:43:00 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (size > 1)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		size--;
	}
}
