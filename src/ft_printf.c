/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:50:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/06 05:06:06 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns the number of characters printed.
*/

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int size;
	char *ret;

	size = 0;
	va_start(ap, fmt);
	size = ft_vasprintf(&ret, fmt, ap);
	va_end(ap);
	return (size);
}
