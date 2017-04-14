/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 00:04:29 by crenfrow          #+#    #+#             */
/*   Updated: 2017/04/14 01:50:19 by crenfrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <float.h>

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	int 					len 	= 0;

	short int 				min_hd 	= -32767;
	short int 				max_hd 	= 32767;
	int 					min_d 	= -32767;
	int 					max_d 	= 32767;
	unsigned short int	 	max_hu 	= 65535;
	long int				min_ld	= -2147483647;
	long int				max_ld	= 2147483647;
	unsigned long int 		max_lu	= 4294967295;
	long long int			min_lld	= -9223372036854775807;
	long long int			max_lld = 9223372036854775807;

	float					min_f = FLT_MIN;
	float					max_f = FLT_MAX;

	char *s_1 = ft_strdup("Hello");
	char *s_2 = ft_strdup("FU");

	printf("printf\n");
	len = printf("Test: %hd -> %hd\n", min_hd, max_hd);
	printf("Len: %d\n", len);
	len = printf("Test: %d -> %d\n", min_d, max_d);
	printf("Len: %d\n", len);
	len = printf("Test: 0 -> %hu\n", max_hu);
	printf("Len: %d\n", len);
	len = printf("Test: %ld -> %ld\n", min_ld, max_ld);
	printf("Len: %d\n", len);
	len = printf("Test: 0 -> %lu\n", max_lu);
	printf("Len: %d\n", len);
	len = printf("Test: %lld -> %lld\n", min_lld, max_lld);
	printf("Len: %d\n", len);
	len = printf("Test: %f -> %f\n", min_f, max_f);
	printf("Len: %d\n", len);
	len = printf("Test: %s -> %s\n", s_1, s_2);
	printf("Len: %d\n", len);
	printf("\n");

	ft_printf("ft_printf\n");
	//len = ft_printf("Test: %hd -> %hd\n", min_hd, max_hd);
	//printf("Len: %d\n", len);
	len = ft_printf("Test: %d -> %d\n", min_d, max_d);
	printf("Len: %d\n", len);
	// len = ft_printf("Test: 0 -> %hu\n", max_hu);
	// printf("Len: %d\n", len);
	// len = ft_printf("Test: %ld -> %ld\n", min_ld, max_ld);
	// printf("Len: %d\n", len);
	// len = ft_printf("Test: 0 -> %lu\n", max_lu);
	// printf("Len: %d\n", len);
	// len = ft_printf("Test: %lld -> %lld\n", min_lld, max_lld);
	// printf("Len: %d\n", len);
	// len = ft_printf("Test: %f -> %f\n", min_f, max_f);
	//printf("Len: %d\n", len);
	len = ft_printf("Test: %s -> %s\n", s_1, s_2);
	printf("Len: %d\n", len);
	ft_printf("\n");

	return (1);
}
