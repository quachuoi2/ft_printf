/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/02 15:31:03 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	convert(char conv, va_list ap)
{
	if (conv == 'c')
		ft_putchar(va_arg(ap, int));
	else if (conv == 'p')
	{
		write(1, "0x", 2);
		ft_d2h((intptr_t)va_arg(ap, void *), 'x');
	}
	else if (conv == 'd' || conv == 'i')
		ft_putnbr(va_arg(ap, int));
	else if (conv == 'o')
		ft_d2o(va_arg(ap, unsigned int));
	else if (conv == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	else if (conv == 'x' || conv == 'X')
		ft_d2h(va_arg(ap, unsigned int), conv);
	else if (conv == 'f')
		va_arg(ap, double);
	else if (conv == 's')
		ft_putstr(va_arg(ap, char *));
	else if (conv == '%')
		ft_putchar(conv);
	else
		ft_putstr_fd("error: unknown conversion type", 2);
}

void	take_subway_order(char **fmt, va_list ap, t_order *order)
{
	(*fmt)++;
	if (**fmt == '%')
	{
		ft_putchar('%');
		return ;
	}
	check_conv(*fmt, order);
	if ((*order).conv == 0)
	{
		ft_putstr_fd("error\n", 2);
		return ;
	}
	check_prefix(*fmt, order);
	convert((*order).conv, ap);
}

int	ft_printf(const char *restrict fmt, ...)
{
	int		char_printed;
	va_list	ap;
	t_order	order;

	initialize_t_order(&order);
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			take_subway_order((char **)&fmt, ap, &order);
		else
			ft_putchar(*fmt);
		*fmt++;
	}
	va_end(ap);
	char_printed = order.pos + order.space + order.hash;
	return (char_printed);
}
