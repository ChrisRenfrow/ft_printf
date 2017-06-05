/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:59:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/18 18:21:59 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

/*
**	Allowed functions:
**	write, malloc, free, exit, va_start, va_arg, va_copy, va_end
*/

typedef struct	s_mod
{
	int			hh:1;
	int			h:1;
	int			l:1;
	int			ll:1;
	int			j:1;
	int			z:1;
	int			none;
}				t_mod;

int 	ft_printf(const char *format, ...);

char 	*fmt_s(va_list ap, t_mod mods);
char 	*fmt_c(va_list ap, t_mod mods);
char 	*fmt_d(va_list ap, t_mod mods);
char 	*fmt_o(va_list ap, t_mod mods);
char 	*fmt_p(va_list ap, t_mod mods);
char 	*fmt_u(va_list ap, t_mod mods);
char 	*fmt_x(va_list ap, t_mod mods);

#endif
