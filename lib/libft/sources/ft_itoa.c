/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:25:32 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/17 20:14:17 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int nb)
{
	char *res;
	int i;
	int neg;
	int rem;
	unsigned int n;

	i = 0;
	neg = 1;
	if (!nb)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		nb = -nb;
		neg = -1;
	}
	n = nb;
	if (!(res = ft_strnew(ft_digilen(n))))
		return (NULL);
	while (n)
	{
		rem = n % 10;
		res[i++] = rem + '0';
		n /= 10;
	}
	if (neg == -1)
		res[i] = '-';
	return (ft_strrev(res));
}
