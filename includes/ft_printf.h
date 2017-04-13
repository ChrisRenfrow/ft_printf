/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:59:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/06 05:51:52 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
**	Allowed functions:
**	write, malloc, free, exit, va_start, va_arg, va_copy, va_end
*/

typedef union	g_flag
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
	int			none;
}				u_flag;

typedef struct	g_arg
{
	u_flag		flag;
	void		*val;
	void		*res;
	ssize_t		size;
}				t_arg;

int 	ft_printf(const char *format, ...);
int		ft_asprintf(char **ret, const char *format, ...);
int		ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
