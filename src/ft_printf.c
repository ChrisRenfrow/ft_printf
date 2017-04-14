/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:50:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/14 01:54:03 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns the number of characters printed.
*/

t_mod	init_modifiers(void)
{
	t_mod mod;

	mod.hh 		= 0;
	mod.h 		= 0;
	mod.l		= 0;
	mod.ll		= 0;
	mod.j		= 0;
	mod.z		= 0;
	mod.none 	= 0;

	return (mod);
}

int		format_handler(t_mod mods, const char **fmt, va_list ap)
{
	(void)mods;
	int len;

	len = 0;
	(*fmt)++;
	if (**fmt == 's') {
		char *s = va_arg(ap, char *);
		len = ft_strlen(s);
		ft_putstr(s);
	} else if (**fmt == 'd') {
		char *s = ft_itoa(va_arg(ap, int));
		len = ft_strlen(s);
		ft_putstr(s);
	} else if (**fmt == '%') {
		ft_putchar('%');
	}
	return (len);
}

int		ft_printf(const char *fmt, ...)
{
	va_list ap;
	int len;
	char *res;

	len = 0;
	t_mod mods = init_modifiers();
	res = ft_strnew(ft_strlen(fmt));
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%') {
			len += format_handler(mods, &fmt, ap);
		} else {
			len++;
			ft_putchar(*fmt);
		}
		fmt++;
	}

	va_end(ap);

	return (len);
}
