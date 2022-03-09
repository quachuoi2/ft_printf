/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:19:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/09 15:33:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_flag(int ammount, char c)
{
	while (ammount-- > 0)
		write(1, &c, 1);
}

int	ft_isacceptable(char c)
{
	if (c == ' ' || c == '#' || c == '-' || c == '+' || c == '.'
		|| c == '@' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
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

void	write_color(char **fmt)
{
	(*fmt)++;
	if (**fmt == 'r')
		write(1, "\x1B[31m", 5);
	else if (**fmt == 'g')
		write(1, "\x1b[32m", 5);
	else if (**fmt == 'b')
		write(1, "\x1B[34m", 5);
	else if (**fmt == 'y')
		write(1, "\x1B[33m", 5);
	else if (**fmt == 'w')
		write(1, "\x1b[37m", 5);
	else if (**fmt == 'd')
		write(1, "\x1b[0m", 5);
}
