/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_util.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:27:31 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_UTIL_H
# define PF_UTIL_H

# include "../../ft_printf.h"

typedef enum	e_position
{
	BEGIN,
	END
}				t_position;

char			*pf_utoa_base(unsigned long long value, int b, char size,
		int hash);
char			*pf_winttostr(wint_t wint);
char			*pf_wstrtostr(wchar_t *s, int max_len);
char			*pf_strjoinchr(char *str, char const chr, int count,
		t_position position);
char			*pf_strjoinchr_begin(char *str, char const chr, int count,
		size_t margin);
char			*pf_strclear(char *str);
char			*pf_zerocut(char *nbr);

#endif
