/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_prefix_adapter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:43:13 by qnguyen           #+#    #+#             */
/*   Updated: 2022/04/13 14:18:57 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	conversion_adapter(void)
{
	set_base();
	set_percent_sign();
	if (g_order.conv == 'f' && g_order.prec == 0)
		g_order.prec = 6;
	else if (g_order.conv == 'f' && g_order.prec == -1)
		g_order.prec = 0;
	else if (g_order.conv == 'p')
		g_order.hash = 1;
	if (g_order.prec < -1)
	{
		g_order.mfw = -g_order.prec;
		g_order.neg = 1;
	}
	if ((g_order.conv != 'p' && g_order.conv != 'c' && g_order.conv != 's'
			&& g_order.prec != 0) || (g_order.prec == 0 && g_order.neg == 1))
			g_order.zero = 0;
}

void	set_base(void)
{
	if (g_order.conv == 'o')
		g_order.base = 8;
	else if (g_order.conv == 'x' || g_order.conv == 'X'
		|| g_order.conv == 'p')
		g_order.base = 16;
	else if (g_order.conv == 'b')
		g_order.base = 2;
}

void	set_percent_sign(void)
{
	if (g_order.conv == '%')
	{
		g_order.prec = 0;
		g_order.pos = 0;
		g_order.space = 0;
		g_order.zero = 0;
	}
}
