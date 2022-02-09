/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:15:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 23:35:38 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	spc_pos(long long n, long double f, t_order order)
{
	if (n >= 0 && f >= 0)
	{
		if (order.pos)
			write(1, "+", 1);
		else if (order.space)
			write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	dif(t_order order, va_list ap)
{
	long long int	n;
	long double		f;

	f = 0;
	n = 0;
	if (order.conv == 'f')
	{
		if (order.flag[0] == 'L')
			f = va_arg(ap, long double);
		else
			f = va_arg(ap, double);
		return (spc_pos(n, f, order) + ft_putfloat(f, 6));
	}
	n = va_arg(ap, long long int);
	int_converter(&n, order, 1);
	return (spc_pos(n, f, order) + ft_putnbr(n));
}
