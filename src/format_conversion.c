/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:45:06 by crenfrow          #+#    #+#             */
/*   Updated: 2017/06/05 14:19:47 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// string
char *fmt_s(va_list ap, t_mod mods)
{
	(void)mods;
	char *str = va_arg(ap, char *);
	return (str);
}

// char
char *fmt_c(va_list ap, t_mod mods)
{
	(void)mods;
	char c = va_arg(ap, int);
	char *s = ft_strnew(1);
	s[0] = c;
	return (s);
}

// int
char *fmt_d(va_list ap, t_mod mods)
{
	(void)mods;
	int d = va_arg(ap, int);
	char *s = ft_itoa(d);
	return (s);
}

// octal
char *fmt_o(va_list ap, t_mod mods)
{
	(void)mods;
	long long int o = va_arg(ap, int);
	o = (o < 0) ? LONG_MAX : o;
	char *s = ft_itoa_base(o, 8);
	return (s);
}

// void * -> hexadecimal
char *fmt_p(va_list ap, t_mod mods)
{
	(void)mods;
	long long int p = va_arg(ap, int);
	p = (p < 0) ? LONG_MAX : p;
	char *s = ft_strjoin("0x", ft_itoa_base(p, 16));
	ft_strtolower(s);
	return (s);
}

// Unsigned
char *fmt_u(va_list ap, t_mod mods)
{
	(void)mods;
	char c = va_arg(ap, int);
	char *s = ft_strnew(1);
	s[0] = c;
	return (s);
}

// Hexadecimal
char *fmt_x(va_list ap, t_mod mods)
{
	(void)mods;
	long long int x = va_arg(ap, int);
	x = (x < 0) ? LONG_MAX : x;
	char *s = ft_itoa_base(x, 16);
	ft_strtolower(s);
	return (s);
}
