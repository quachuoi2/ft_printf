/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:19:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/15 22:58:35 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_flag(int ammount, char c)
{
	while (ammount-- > 0)
		write(1, &c, 1);
}

void	a_wild_mfw_appeared(t_order *order, va_list ap, char mfw_prec)
{
	int	n;

	n = va_arg(ap, int);
	if (n < 0)
	{
		if ((*order).mfw)
			return ;
		n = -n;
		(*order).neg = 1;
	}
	if (mfw_prec == 'm')
		(*order).mfw = n;
	else if (mfw_prec == 'p' && n == 0)
		(*order).prec = -1;
	else if (mfw_prec == 'p' && (*order).neg == 0)
		(*order).prec = n;
}

void	mfw_prec_assigner(t_order *order, char **fmt, va_list ap)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			a_wild_mfw_appeared(order, ap, 'p');
			(*fmt)++;
			return ;
		}
		if (ft_atoi(*fmt) == 0)
			(*order).prec = -1;
		else
			(*order).prec = ft_atoi(*fmt);
	}
	else
		(*order).mfw = ft_atoi(*fmt);
}

void	write_color(char **fmt, char *default_color)
{
	char	*color;

	(*fmt)++;
	if (**fmt == 'r')
		color = "\x1B[31m";
	else if (**fmt == 'g')
		color = "\x1B[32m";
	else if (**fmt == 'b')
		color = "\x1B[34m";
	else if (**fmt == 'y')
		color = "\x1B[33m";
	else if (**fmt == 'w')
		color = "\x1B[37m";
	else if (**fmt == 'd')
		color = "\x1B[0m";
	if (default_color)
		ft_strcpy(default_color, color);
	write(1, color, 5);
}

int	grouping_grouper(char **fmt, va_list ap,
			char *default_color, t_order *order)
{
	int	char_printed;

	char_printed = 0;
	if (**fmt == '%')
	{
		char_printed = take_subway_order(fmt, ap, order);
		if ((*order).color)
			write(1, default_color, 5);
	}
	else if (**fmt == '@')
		write_color((char **)fmt, default_color);
	else
		char_printed += ft_putchar(**fmt);
	return (char_printed);
}
