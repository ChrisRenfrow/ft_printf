/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:59:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/01 22:19:48 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*
**	Allowed functions:
**	write, malloc, free, exit, va_start, va_arg, va_copy, va_end
*/

int 		ft_printf(const char *format, ...);
ssize_t		ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
