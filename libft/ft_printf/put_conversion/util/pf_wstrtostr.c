/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:27:41 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_util.h"

char	*pf_wstrtostr(wchar_t *s, int max_len)
{
	char	*wint_tmp;
	char	*tmp;
	char	*str;
	size_t	size;

	if (!s)
		return (ft_strdup("(null)"));
	size = 0;
	str = ft_strdup("");
	while (s[size])
	{
		tmp = str;
		wint_tmp = pf_winttostr(s[size]);
		str = ft_strjoin(str, wint_tmp);
		free(wint_tmp);
		if (max_len >= 0 && (int)ft_strlen(str) > max_len)
		{
			free(str);
			str = tmp;
			break ;
		}
		free(tmp);
		size++;
	}
	return (str);
}
