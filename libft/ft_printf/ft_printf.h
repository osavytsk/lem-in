/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:28:34 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:25:19 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"
# include "put_conversion/put/pf_put.h"

typedef enum	e_size
{
	N,
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_size;

typedef struct	s_conversion
{
	int			minimum_width;
	int			precision;
	int			hashtag;
	int			apostrophe;
	int			ldouble;
	char		padding;
	char		sign;
	t_size		size;
	int			type;

}				t_conversion;

size_t			pf_parse(const char *f, size_t i, va_list valist);
void			pf_put_conversion(t_conversion *conv, va_list valist);

#endif
