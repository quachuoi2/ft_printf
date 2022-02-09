/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:16:45 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 13:16:58 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	csp(t_order order, va_list ap)
{
	char			*s;

	if (order.conv == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (order.conv == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else if (order.conv == 'p')
	{
		write(1, "0x", 2);
		return (ft_d2base((intptr_t)va_arg(ap, void *), 16, 0, 'x') + 2);
	}
}
