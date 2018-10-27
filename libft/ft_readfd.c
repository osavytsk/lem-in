/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 05:18:35 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:20:25 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfd(int fd)
{
	ssize_t	size;
	char	buffer[BUFF_SIZE + 1];
	char	*result;

	result = NULL;
	while ((size = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[size] = '\0';
		if (result == NULL)
			result = ft_strdup("");
		result = ft_strfjoin(result, buffer, FIRST);
	}
	return (result);
}
