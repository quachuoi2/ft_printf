/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:42:06 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 18:43:07 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hash(t_order order)
{
	if (order.hash || order.conv == 'p')
	{
		write(1, "0", 1);
		if (order.conv == 'X')
			write(1, "X", 1);
		else
			write(1, "x", 1);
	}
}

void	spc_pos(t_order order)
{
	if (order.pos)
		write(1, "+", 1);
	else if (order.space)
		write(1, " ", 1);
}

int	mfw(int i, t_order order)
{
	int	temp;

	temp = i;
	while (i < order.mfw)
	{
		if (!order.zero)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		i++;
	}
	if (temp < order.mfw)
		return (order.mfw - temp);
	return (0);
}

void bundling_bundler(int *i, void (*f)(t_order), t_order order)
{
	if (order.zero == 1)
		f(order);
	*i += mfw(*i, order);
	if (order.zero == 0)
		f(order);
}
