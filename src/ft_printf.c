/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:50:25 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/05 14:17:04 by crenfrow         ###   ########.fr       */
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

int		print_with_fmt(char *(*func)(va_list, t_mod), t_mod mods, va_list ap)
{
	int len = 0;
	char *out;
	out = func(ap, mods);
	len = ft_strlen(out);
	ft_putstr(out);
	return (len);
}

t_mod 	len_handler(const char *fmt)
{
	t_mod mod = init_modifiers();
	while (*fmt == 'h' || *fmt == 'l' || *fmt == 'j' || *fmt == 'z') {
		if (*fmt == 'h') {
			if (mod.h)
				mod.hh = 1;
		} else if (*fmt == 'l') {
			if (mod.ll)
				mod.ll = 1;
		} else if (*fmt == 'j') {
			mod.j = 1;
		} else if (*fmt == 'z') {
			mod.z = 1;
		}
		fmt++;
	}
	return (mod);
}

int		format_handler(const char **fmt, va_list ap)
{
	int len;

	len = 0;
	(*fmt)++;
	t_mod mods = len_handler(*fmt);
	if (**fmt == 's') {
		len = print_with_fmt(&fmt_s, mods, ap);
	} else if (**fmt == 'c') {
		len = print_with_fmt(&fmt_c, mods, ap);
	} else if (**fmt == 'd') {
		len = print_with_fmt(&fmt_d, mods, ap);
	} else if (**fmt == 'i') {
		len = print_with_fmt(&fmt_d, mods, ap);
	} else if (**fmt == 'o') {
		len = print_with_fmt(&fmt_o, mods, ap);
	} else if (**fmt == 'p') {
		len = print_with_fmt(&fmt_p, mods, ap);
	} else if (**fmt == 'u') {
		len = print_with_fmt(&fmt_u, mods, ap);
	} else if (**fmt == 'x') {
		len = print_with_fmt(&fmt_x, mods, ap);
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
	res = ft_strnew(ft_strlen(fmt));
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%') {
			len += format_handler(&fmt, ap);
		} else {
			len++;
			ft_putchar(*fmt);
		}
		fmt++;
	}

	va_end(ap);

	return (len);
}
