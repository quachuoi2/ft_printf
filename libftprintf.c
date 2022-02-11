/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 20:13:36 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert(t_order order, va_list ap, char **og_fmt)
{
	int i;

	i = 0;
	if (order.conv == 'c' || order.conv == 's')
		return (cs(order, ap));
	else if (order.conv == 'd' || order.conv == 'i' || order.conv == 'f')
		return (dif(order, ap));
	else if (order.conv == 'o' || order.conv == 'u' || order.conv == 'x'
		|| order.conv == 'X'  || order.conv == 'p')
		return (pouxx(order, ap));
	while (**og_fmt != '%' && **og_fmt)
	{
		write(1, *og_fmt, 1);
		i++;
		(*og_fmt)++;
		return (i);
	}
/* 	ft_putstr_fd("error: unknown conversion type\n", 2);
	exit(0); */
}

int	take_subway_order(char **fmt, va_list ap, t_order *order)
{
	char **og_fmt;

	og_fmt = fmt;
	(*fmt)++;
	initialize_t_order(order);
	if (**fmt == '%')
		return (ft_putchar('%'));
	check_prefix(fmt, order);
	//printf("\nafterprefix %d-%d\n", **fmt, (*order).prec);
	check_flag(fmt, order);
	check_conv(fmt, order);
	//printf("\nspc - %d\nhash - %d\nzero - %d\nneg - %d\npos - %d\nmwf - %d\nprec - %d\nflag - %c%c\nconv - %c\n", (*order).space, (*order).hash, (*order).zero, (*order).neg, (*order).pos, (*order).mfw, (*order).prec, (*order).flag[0], (*order).flag[1], (*order).conv);
	return (convert(*order, ap, og_fmt));
}
	/* if (!repeated_flag(*order))
		return (0); */

int	ft_printf(const char *restrict fmt, ...)
{
	int		char_printed;
	va_list	ap;
	t_order	order;

	va_start(ap, fmt);
	char_printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			char_printed += take_subway_order((char **)&fmt, ap, &order);
		else
			char_printed += ft_putchar(*fmt);
		if (*fmt == '\0')
			break;
		fmt++;
	}
	va_end(ap);
	return (char_printed);
}
