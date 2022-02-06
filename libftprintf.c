/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/06 23:40:45 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert(char conv, va_list ap)
{
	int				d;
	char			*s;
	unsigned int	u;
	unsigned int	o;

	if (conv == 'c')
	{
		ft_putchar(va_arg(ap, int));
		return (1);
	}
	else if (conv == 'p')
	{
		write(1, "0x", 2);
		return (ft_d2base((intptr_t)va_arg(ap, void *), 16, 0, 'x') + 2);
	}
	else if (conv == 'd' || conv == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		return (ft_diglen(d));
	}
	else if (conv == 'o')
		return (ft_d2base(va_arg(ap, unsigned int), 8, 0, 'o'));
	else if (conv == 'u')
	{
		u = va_arg(ap, unsigned int);
		ft_putnbr(u);
		return (ft_diglen((unsigned int)u));
	}
	else if (conv == 'x' || conv == 'X')
		return (ft_d2base(va_arg(ap, unsigned int), 16, 0, conv));
	else if (conv == 'f')
		return (ft_putfloat(va_arg(ap, double), 6));
	else if (conv == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
		return (ft_strlen(s));
	}
	else
	{
		ft_putstr_fd("error: unknown conversion type", 2);
		exit(0);
	}
}

int	take_subway_order(char **fmt, va_list ap, t_order *order)
{
	(*fmt)++;
	initialize_t_order(order);
	if (**fmt == '%')
	{
		ft_putchar('%');
		return (1);
	}
	check_conv(*fmt, order);
	if ((*order).conv == 0)
	{
		//ft_putstr_fd("error\n", 2);
		exit(0);
	}
	check_prefix(*fmt, order);
	return (convert((*order).conv, ap));
}

int	ft_printf(const char *restrict fmt, ...)
{
	char	*temp;
	int		char_printed;
	va_list	ap;
	t_order	order;

	va_start(ap, fmt);
	temp = (char *)fmt;
	while (*fmt)
	{
		if (*fmt == '%')
			char_printed = take_subway_order((char **)&fmt, ap, &order) - 2;
		else
			ft_putchar(*fmt);
		*fmt++;
	}
	va_end(ap);
	char_printed += order.pos + order.space + order.hash + order.mfw + order.prec + (fmt - temp);
	return (char_printed);
}
