/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/09 15:35:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_function	*g_function_arr[10] = {put_c, put_s, put_d, put_f, put_pbouxx};

int	convert(t_order *order, va_list ap, char *og_fmt, char *fmt)
{
	int	i;

	if ((*order).conv != 0 && (*order).conv != '%')
		return (g_function_arr[(*order).func_idx](order, ap));
	else if ((*order).conv == '%')
		return (ft_putchar('%'));
	i = 0;
	while (og_fmt <= fmt && *og_fmt)
	{
		if (*og_fmt == '*')
			ft_putnbr((*order).mfw);
		else if (*og_fmt != '0')
			write(1, og_fmt, 1);
		if (*og_fmt == '.' && !ft_isdigit(og_fmt[1]))
			write(1, "0", 1);
		i++;
		og_fmt++;
	}
	return (i);
}

int	take_subway_order(char **fmt, va_list ap, t_order *order)
{
	char	*og_fmt;

	og_fmt = *fmt;
	(*fmt)++;
	if (!**fmt)
		return (0);
	initialize_t_order(order);
	check_prefix(fmt, order, ap);
	check_flag(fmt, order);
	check_conv(fmt, order);
	conversion_appropriation(order);
	return (convert(order, ap, og_fmt, *fmt));
}

int	ft_printf(const char *fmt, ...)
{
	int		char_printed;
	va_list	ap;
	t_order	order;

	va_start(ap, fmt);
	char_printed = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			char_printed += take_subway_order((char **)&fmt, ap, &order);
			if (order.neg)
				put_flag(order.num_of_padding, ' ');
		}
		else
			char_printed += ft_putchar(*fmt);
		if (*fmt == '\0')
			break ;
		fmt++;
	}
	va_end(ap);
	return (char_printed);
}
