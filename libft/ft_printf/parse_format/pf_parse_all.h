/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_all.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:25:38 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PARSE_ALL_H
# define PF_PARSE_ALL_H

# include "../ft_printf.h"

size_t	pf_parse_flags(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_type(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_minwidth(const char *f, size_t i, t_conversion *form,
		va_list v);
size_t	pf_parse_precision(const char *f, size_t i, t_conversion *form,
		va_list v);
size_t	pf_parse_size(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_brace(const char *f, size_t i, va_list valist);
size_t	pf_free_brace(char **colors, char **escapes, size_t i);

#endif
