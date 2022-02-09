/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:54:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 23:36:55 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	a = 'q';
	int	i;
	char	*p;
	long long int x = 142;
	p = ft_strdup("mroo");
	//ft_printf("ft - %cuachuoi%d\n%s - %p\n", a, 2, p, p);
	i = printf("moro: %hhd\n", x);
	printf("og: %ld\n", i);
	i = ft_printf("4242: %hhd\n", x);
	printf("42: %d\n", i);
	free(p);
	return (0);
}
