/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:15:23 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 13:15:43 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	spc_pos(int n, double f, t_order order)
{
	if (n >= 0 && f >= 0)
	{
		if (order.pos)
			write(1, "+", 1);
		else if (order.space)
			write(1, " ", 1);
	}
}

int	dif(t_order order, va_list ap)
{
	int			count;
	double		f;
	long long	n;

	count = 0;
	f = 0;
	n = 0;
	if (order.conv == 'f')
	{
		f = va_arg(ap, double);
		return (ft_putfloat(f, 6) + spc_pos(n, f, order));
	}
	n = va_arg(ap, int);
	return (ft_putnbr(n) + spc_pos(n, f, order));
}
