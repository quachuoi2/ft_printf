/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:15:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 06:09:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	dif(t_order order, va_list ap)
{
	long long int	n;
	long double		f;
	int				i;

	f = 0;
	n = 0;
	i = (order.space || order.pos );
	if (order.conv == 'f')
	{
		if (order.flag[0] == 'L')
			f = va_arg(ap, long double);
		else
			f = va_arg(ap, double);
		i += ft_diglen(f) + order.prec + (order.prec != 0);
		bundling_bundler(&i, &spc_pos, &order);
		ft_putfloat(f, order.prec);
		return (i);
	}
	n = va_arg(ap, long long int);
	int_converter(NULL, &n, order);
	i += ft_diglen(n);
	bundling_bundler(&i, &spc_pos, &order);
	ft_putnbr(n);
	return (i);
}
