/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/17 20:07:41 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_function	*g_function_arr[5] = {put_c, put_s, put_d, put_f, put_pbouxx};

int	print_error(t_order *order, char *og_fmt, char *fmt,
		char (*default_color)[5])
{
	int	i;

	while (og_fmt <= fmt && *og_fmt)
	{
		write(1, *default_color, 5);
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

int	take_subway_order(char **fmt, va_list ap, t_order *order,
			char (*default_color)[5])
{
	char	*og_fmt;
	int		i;

	og_fmt = *fmt;
	(*fmt)++;
	if (!**fmt)
		return (0);
	initialize_t_order(order);
	check_prefix(fmt, order, ap);
	check_flag(fmt, order);
	check_conv(fmt, order);
	conversion_appropriation(order);
	if ((*order).conv != 0)
	{
		i = g_function_arr[(*order).func_idx](order, ap);
		if ((*order).neg)
			put_flag((*order).num_of_padding, ' ');
		return (i);
	}
	return (print_error(order, og_fmt, *fmt, default_color));
}

int	grouping_grouper(char **fmt, va_list ap,
			char (*default_color)[5], t_order *order)
{
	int	char_printed;

	char_printed = 0;
	if (**fmt == '%')
	{
		char_printed = take_subway_order(fmt, ap, order, default_color);
		if ((*order).color)
			write(1, *default_color, 5);
	}
	else if (**fmt == '$')
		write_color((char **)fmt, default_color);
	else
		char_printed += ft_putchar(**fmt);
	return (char_printed);
}

int	ft_printf(const char *fmt, ...)
{
	char	default_color[5];
	int		char_printed;
	va_list	ap;
	t_order	order;

	ft_strcpy(default_color, "\x1b[0m");
	va_start(ap, fmt);
	char_printed = 0;
	while (*fmt)
	{
		char_printed += grouping_grouper((char **)&fmt, ap,
				&default_color, &order);
		if (*fmt)
			fmt++;
	}
	va_end(ap);
	return (char_printed);
}
