/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 21:46:09 by crenfrow          #+#    #+#             */
/*   Updated: 2017/01/06 05:54:37 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ft_vasprintf takes in a pointer to a buffer and allocates with malloc(3)
** enough space to store the formatted string using format and arguments from ap
*/

//*ret = va_arg(ap, char*);

u_flag	init_flag()
{
	u_flag flag;

	flag.hh =	0;
	flag.h =	0;
	flag.l =	0;
	flag.ll =	0;
	flag.j =	0;
	flag.z =	0;
	flag.none =	0;

	return (flag);
}

t_arg	*handle_flag(char *fmt, void *arg_val)
{
	u_flag flag;
	flag = init_flag();
	t_arg *arg = (t_arg*)malloc(sizeof(t_arg));
	if (*(++fmt) == 's')
	{
		flag.none++;
		arg->flag = flag;
		arg->val = arg_val;
		arg->res = arg_val;
		arg->size = ft_strlen(arg_val);
	}
	return (arg);
}

int		ft_vasprintf(char **ret, const char *fmt, va_list ap)
{
	int i;
	t_list *arglist;
	t_arg *arg;

	i = 0;
	arglist = (t_list*)malloc(sizeof(t_list));
	while (fmt[i] != 0)
	{
		if (fmt[i] == '%')
		{
			arg = handle_flag((char*)fmt, va_arg(ap, void*));
			t_list *node = (t_list*)malloc(sizeof(t_list));
			node->content = arg;
			ft_lstadd(&arglist, node);
		}
		i++;
	}
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i += 2;
		
	}

	return (ft_strlen(*ret));
}
