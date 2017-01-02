/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 21:46:09 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/02 00:24:28 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "libft.h"

//static char args[] = "sSpdDioOuUxXcC\0";

ssize_t		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	/*
	** Handles the actual variatic element of printf
	*/

	while (*format)
	{
		format++;
		if (*format == 's')
		{
			*ret = va_arg(ap, char*);
			printf("%s\n", *ret);
		}
	}
	return ((ssize_t)ft_strlen(*ret));
}
