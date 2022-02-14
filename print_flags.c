/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:42:06 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 06:16:39 by qnguyen          ###   ########.fr       */
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

int	prec(int i, t_order *order)
{
	int	i2;

	i2 = 0;
	while (i < (*order).mfw)
	{
		write(1, "0", 1);
		i++;
		i2++;
	}
	return (i2);
}

int	mfw(int i, t_order order)
{
	int	i2;
	int	padding;

	if (i < order.mfw)
	{
		i2 = 0;
		padding = order.mfw - ft_greaternum(i, order.prec);
		while (i2 < padding)
		{
			if (!order.zero)
				write(1, " ", 1);
			else
				write(1, "0", 1);
			i2++;
		}
		return (i2);
	}
	return (0);
}
