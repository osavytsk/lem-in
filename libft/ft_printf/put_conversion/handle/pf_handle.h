/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:28:44 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_HANDLE_H
# define PF_HANDLE_H
# define FLOAT_SIZE 1024

# include "../util/pf_util.h"

typedef struct	s_time
{
	int			year;
	int			month;
	int			day;
	int			hour;
	int			min;
	int			sec;
}				t_time;

char			*pf_handle_minwidth(t_conversion *conv, char *str,
		size_t margin);
char			*pf_handle_precision(t_conversion *c, char *str, int l,
		size_t m);
t_time			*pf_handle_time(const unsigned long long time);
char			*pf_handle_apostrophe(char *nbr);
char			*pf_handle_a(long double nbr, t_conversion *c);
char			*pf_create_time(char *t1, int n2, char *delim);
void			pf_ftoa_conv(char *outstr, long double nbr, t_conversion *c);

#endif
