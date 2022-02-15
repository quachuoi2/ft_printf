/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:42:06 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/15 02:31:40 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hash(t_order order)
{
	if (order.hash || order.conv == 'p')
	{
		write(1, "0", 1);
		if (order.conv != 'o')
		{
			if (order.conv == 'X')
				write(1, "X", 1);
			else
				write(1, "x", 1);
			return (2);
		}
		return (1);
	}
	return (0);
}

int	spc_pos(t_order order)
{
	if (order.pos || order.space)
	{
		if (order.pos)
			write(1, "+", 1);
		else
			write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	zero(int i, t_order order)
{
	int	z_count;
	int zero;

	zero = 0;
	if (order.prec == 0) // %6d %06d
	{
		zero = order.mfw - (order.pos || order.space) - i;
		if (order.hash == 1 && order.conv == 'o')
			zero -= 1;
		else if (order.hash == 1)
			zero -= 2;
	}
	else if (order.prec != 0)
	{
		if (order.mfw > i) //%10.6d
			zero = order.mfw - i;
		else if (order.prec > i) //%.6d %.6x
			zero = order.prec - i;
	}
	z_count = 0;
	while (z_count++ < zero)
		write(1, "0", 1);
	return ((zero > 0) * zero);
}

int	padding(int i, t_order order)
{
	int	p_count;
	int	padding;

	padding = 0;
	padding = order.mfw - (order.pos || order.space) - i; //6d
	if (order.prec > i) //.6d 10.6d
		padding -= order.prec - i;
	if (order.hash == 1 && order.conv == 'o')
		padding -= 1;
	else if (order.hash == 1)
		padding -= 2;
	p_count = 0;
	while (p_count++ < padding)
		write(1, " ", 1);
	return ((padding > 0) * padding);
}

int	mfw(int i, t_order order, int (*f)(t_order))
{
	int i2;

	i2 = 0;
 	if (i < order.mfw || i < order.prec)
	{
		if (order.zero || order.mfw < i)
		{
			if (f)
				i2 += f(order);
			i2 += zero(i, order);
			return (i2);
		}
		i2 += padding(i, order);
	}
	if (f)
		i2 += f(order);
	return (i2);
}

//hash (and maybe pos/spc) isnt called if length is > mfw

//why does %di not work when spc/pos is precalculated but ouxX does when hash is
