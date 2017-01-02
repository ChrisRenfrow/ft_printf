/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:50:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/01 22:51:27 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns the number of characters printed.
*/

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	ssize_t ret;
	char *str;

	ret = 0;
	va_start(ap, fmt);
	ret = ft_vasprintf(&str, fmt, ap);
	va_end(ap);
	return (ret);
}
