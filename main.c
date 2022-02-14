/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 06:12:37 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	a = 'q';
	int	i = 0;
	char	*p;
	double f = 123.456;
	//4294967295
	//18446744073709551615
	p = NULL;
	//ft_printf("ft - %cuachuoi%d\n%s - %p\n", a, 2, p, p);
	/* i = printf("moro: %0#-5 %d\n", 7);
	printf("og: %d\n", i); */
	i = printf("og:% 5dz\n", 97);
	printf("og: %d\n", i);
	i = ft_printf("42:% 5dz\n", 97);
	ft_printf("42: %d\n", i);
	free(p);
	return (0);
}
