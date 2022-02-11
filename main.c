/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 20:22:58 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	a = 'q';
	int	i;
	char	*p;
	double f = 123.456;
	//4294967295
	//18446744073709551615
	p = NULL;
	//ft_printf("ft - %cuachuoi%d\n%s - %p\n", a, 2, p, p);
	/* i = printf("moro: %0#-5 %d\n", 7);
	printf("og: %d\n", i); */
	i = printf("moro: %.0f\n", f);
	printf("og: %d\n", i);
	//i = printf("nm  : %f\n", f);
	i = ft_printf("42  : %.0f\n", f);
	ft_printf("total: %d\n", i);
	free(p);
	return (0);
}
