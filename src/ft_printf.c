/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:50:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/17 18:49:24 by crenfrow         ###   ########.fr       */
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

int		print_using_fmt(char *(*func)(va_list), va_list ap)
{
	int len = 0;
	char *out;
	out = func(ap);
	len = ft_strlen(out);
	ft_putstr(out);
	return (len);
}

int		format_handler(t_mod mods, const char **fmt, va_list ap)
{
	(void)mods;
	int len;

	len = 0;
	(*fmt)++;
	if (**fmt == 's') {
		len = print_using_fmt(&fmt_s, ap);
	} else if (**fmt == 'c') {
		len = print_using_fmt(&fmt_c, ap);
	} else if (**fmt == 'd') {
		len = print_using_fmt(&fmt_d, ap);
	} else if (**fmt == 'i') {
		len = print_using_fmt(&fmt_d, ap);
	} else if (**fmt == 'o') {
		len = print_using_fmt(&fmt_o, ap);
	} else if (**fmt == 'p') {
		len = print_using_fmt(&fmt_p, ap);
	} else if (**fmt == 'u') {
		len = print_using_fmt(&fmt_u, ap);
	} else if (**fmt == 'x') {
		len = print_using_fmt(&fmt_x, ap);
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
