/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:41:59 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *str, int val, size_t num)
{
	unsigned char	*s;
	size_t			i;

	i = 0;
	s = str;
	if (num == 0)
		return (str);
	while (i < num)
		s[i++] = (unsigned char)val;
	return (str);
}
