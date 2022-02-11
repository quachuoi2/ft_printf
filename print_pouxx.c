/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pouxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:42:41 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 18:42:55 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	pouxx(t_order order, va_list ap)
{
	int						i;
	unsigned long long int	u;

	i = (order.hash == 1 || order.conv == 'p') * 2 - (order.conv == 'o');
	if (order.conv == 'p')
	{
		u = (intptr_t)va_arg(ap, void *);
		if (u == 0)
		{
			write (1, "(nil)", 5);
			return (5);
		}
	}
	else
		u = va_arg(ap, unsigned long long int);
	if (order.conv != 'p')
		int_converter(&u, NULL, order);
	i += ft_udiglen(u, order.base);
	bundling_bundler(&i, &hash, order);
	ft_d2base(u, order.base, order.conv);
	return (i);
}
