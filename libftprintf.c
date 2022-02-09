/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/09 13:37:43 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	convert(t_order order, va_list ap)
{
	int				count;

	if (order.conv == 'c' || order.conv == 's' || order.conv == 'p')
		return (csp(order, ap));
	else if (order.conv == 'd' || order.conv == 'i' || order.conv == 'f')
		return (dif(order, ap));
	else if (order.conv == 'o' || order.conv == 'u' || order.conv == 'x'
		|| order.conv == 'X')
		return (ouxX(order, ap));
	ft_putstr_fd("error: unknown conversion type", 2);
	exit(0);
}

int	take_subway_order(char **fmt, va_list ap, t_order *order)
{
	(*fmt)++;
	initialize_t_order(order);
	if (**fmt == '%')
		return (ft_putchar('%'));
	check_prefix(fmt, order);
	check_flag(fmt, order);
	check_conv(fmt, order);
//	printf("\nspc - %d\nhash - %d\nzero - %d\nneg - %d\npos - %d\nmwf - %d\nprec - %d\nflag - %c%c\nconv - %c\n", (*order).space, (*order).hash, (*order).zero, (*order).neg, (*order).pos, (*order).mfw, (*order).prec, (*order).flag[0], (*order).flag[1], (*order).conv);
	/* if (!empty_conv(*order, **fmt) || !repeated_flag(*order))
		return (0); */
	return (convert(*order, ap));
}

int	ft_printf(const char *restrict fmt, ...)
{
	char	*temp;
	int		char_printed = 0;
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
		//char_printed += order.pos + order.space + order.hash + order.mfw + order.prec;
		*fmt++;
	}
	//char_printed += (fmt - temp);
	va_end(ap);
	return (char_printed);
}
