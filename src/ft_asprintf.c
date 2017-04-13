/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 03:56:46 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/06 05:30:34 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_asprintf takes in a pointer to a buffer and allocates with malloc(3)
** enough space to store the formatted string using format and any additional
** args
*/

int		ft_asprintf(char **ret, const char *fmt, ...)
{
	va_list ap;
	int size;

	size = 0;
	va_start(ap, fmt);
	size = ft_vasprintf(ret, fmt, ap);
	va_end(ap);
	return(size);
}
