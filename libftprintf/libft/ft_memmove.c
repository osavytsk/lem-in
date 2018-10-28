/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:41:57 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*psrc;
	char	*pdst;

	psrc = (char*)src;
	pdst = (char*)dst;
	if (psrc < pdst)
		while (len > 0)
		{
			len--;
			*(pdst + len) = *(psrc + len);
		}
	else
		pdst = ft_memcpy(pdst, psrc, len);
	return (dst);
}
