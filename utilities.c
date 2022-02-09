/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:56:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 23:25:41 by qnguyen          ###   ########.fr       */
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

int	repeated_flag(t_order order)
{
	ft_putstr_fd("repeated '", 2);
	if (order.space > 1)
		ft_putchar_fd(' ', 2);
	if (order.hash > 1)
		ft_putchar_fd('#', 2);
	if (order.zero > 1)
		ft_putchar_fd('#', 2);
	if (order.neg > 1)
		ft_putchar_fd('-', 2);
	if (order.pos > 1)
		ft_putchar_fd('+', 2);
	ft_putstr_fd("' flag in format\n", 2);
	return (0);
}

void	int_converter(long long int *n, t_order order, char sign)
{
	if (sign == 1)
	{
		if (order.flag[0] == 0)
			*n = (int)*n;
		else if (order.flag[1] == 'h')
			*n = (char)*n;
		else if (order.flag[0] == 'h')
			*n = (short)*n;
		else if (order.flag[1] == 'l')
			return ;
		else if (order.flag[0] == 'l')
			*n = (long)*n;
	}
	else
	{
		if (order.flag[0] == 0)
			*n = (unsigned int)*n;
		else if (order.flag[1] == 'h')
			*n = (unsigned char)*n;
		else if (order.flag[0] == 'h')
			*n = (unsigned short)*n;
		else if (order.flag[1] == 'l')
			return ;
		else if (order.flag[0] == 'l')
			*n = (unsigned long)*n;
	}
}
