/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 13:30:58 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	a = 'q';
	int	i;
	char	*p;

	p = ft_strdup("mroo");
	//ft_printf("ft - %cuachuoi%d\n%s - %p\n", a, 2, p, p);
/* 	i = printf("%+ d\n", 42);
	printf("%d\n", i); */
	i = ft_printf("%#X\n", 496848);
	printf("42: %d\n", i);
	free(p);
	return (0);
}
