/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:56:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 19:59:48 by qnguyen          ###   ########.fr       */
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
	(*order).base = 10;
}

void	int_converter(unsigned long long int *u, long long *n, t_order order)
{
	if (n != NULL)
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
		return ;
	}
	if (order.flag[0] == 0)
		*u = (unsigned int)*u;
	else if (order.flag[1] == 'h')
		*u = (unsigned char)*u;
	else if (order.flag[0] == 'h')
		*u = (unsigned short)*u;
	else if (order.flag[1] == 'l')
		return ;
	else if (order.flag[0] == 'l')
		*u = (unsigned long)*u;
}


int	ft_isacceptable(char c)
{
	if (c == ' ' || c == '#' || c == '-' || c == '+' || c == '.'
		|| ft_isdigit(c))
		return (1);
	return (0);
}
/* int	repeated_flag(t_order order)
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
} */
