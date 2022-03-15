/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/15 22:57:46 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_function	*g_function_arr[5] = {put_c, put_s, put_d, put_f, put_pbouxx};

int	convert(t_order *order, va_list ap, char *og_fmt, char *fmt)
{
	int	i;

	if ((*order).conv != 0)
	{
		i = g_function_arr[(*order).func_idx](order, ap);
		if ((*order).neg)
			put_flag((*order).num_of_padding, ' ');
		return (i);
	}
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
	char	*default_color;
	int		char_printed;
	va_list	ap;
	t_order	order;

	default_color = ft_strdup("\x1b[0m");
	va_start(ap, fmt);
	char_printed = 0;
	while (*fmt)
	{
		char_printed
			+= grouping_grouper((char **)&fmt, ap, default_color, &order);
		if (*fmt)
			fmt++;
	}
	free(default_color);
	va_end(ap);
	return (char_printed);
}
