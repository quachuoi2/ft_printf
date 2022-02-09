/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:56:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 13:17:49 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_t_order(t_order *order)
{
	(*order).space = 0;
	(*order).hash = 0;
	(*order).zero = 0;
	(*order).neg = 0;
	(*order).pos = 0;
	(*order).mfw = 0;
	(*order).prec = 0;
	(*order).flag[0] = 0;
	(*order).flag[1] = 0;
	(*order).conv = 0;
}

int	empty_conv(t_order order, char c)
{
	if (order.conv ==  0)
	{
		ft_putstr("unknown conversion: ");
		ft_putchar(c);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

int	repeated_flag(t_order order)
{
	int	i;
	int	n[5];

	i = 0;
	n[0] = order.space;
	n[1] = order.hash;
	n[2] = order.zero;
	n[3] = order.neg;
	n[4] = order.pos;
	while (i < 5)
	{
		if (n[i] > 1)
		{
			ft_putstr("repeated ");
			ft_putchar('@');
			ft_putstr(" flag in format\n");
			return (0);
		}
		i++;
	}
	return (1);
}
