/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ouxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:17:52 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 23:27:11 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hash(t_order order)
{
	if (order.hash)
	{
		write(1, "0", 1);
		if (order.conv == 'o')
			return (1);
		write(1, &order.conv, 1);
		return (2);
	}
	return (0);
}

int	ouxX(t_order order, va_list ap)
{
	unsigned long long int	n;

	n = va_arg(ap, unsigned long long int);
	int_converter(&n, order, 0);
	if (order.conv == 'u')
		return (ft_putnbr(n));
	if (order.conv == 'o')
		return (hash(order) + ft_d2base(n, 8, 0, order.conv));
	return (hash(order) + ft_d2base(n, 16, 0, order.conv));
}
