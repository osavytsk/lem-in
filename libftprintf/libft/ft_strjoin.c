/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:40:49 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:43:35 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (s1 == NULL || s2 == NULL
		|| (dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	dst = ft_strcat(dst, s2);
	return (dst);
}
