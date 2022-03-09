/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:17:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/09 15:33:48 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	helping_helper(t_order *order, char fmt)
{
	(*order).space += (fmt == ' ');
	(*order).hash += (fmt == '#');
	(*order).zero += (fmt == '0');
	(*order).neg += (fmt == '-');
	(*order).pos += (fmt == '+');
}

void	check_prefix(char **fmt, t_order *order, va_list ap)
{
	while (ft_isacceptable(**fmt))
	{
		if ((*order).mfw == 0 && (*order).prec == 0)
			helping_helper(order, **fmt);
		if ((**fmt >= '1' && **fmt <= '9') || **fmt == '.')
		{
			mfw_prec_assigner(order, fmt, ap);
			while (ft_isdigit(**fmt) || **fmt == '-' || **fmt == '+')
				(*fmt)++;
			if (**fmt != '.')
				return ;
			(*fmt)--;
		}
		else if (**fmt == '@')
			write_color(fmt);
		else if (**fmt == '*')
			a_wild_mfw_appeared(order, ap, 'm');
		(*fmt)++;
	}
}

void	check_flag(char **fmt, t_order *order)
{
	if (**fmt == 'h' || **fmt == 'l' || **fmt == 'L')
	{
		if ((*fmt)[1] == **fmt)
		{
			(*order).flag[1] = **fmt;
			(*fmt)++;
		}
		(*order).flag[0] = **fmt;
		(*fmt)++;
	}
}

void	check_conv(char **fmt, t_order *order)
{
	char	conv[13];
	int		i;

	ft_strcpy(conv, "csdfpbouxX %\0");
	i = -1;
	while (conv[++i])
	{
		if (**fmt == conv[i])
		{
			(*order).conv = **fmt;
			if (i < 4)
				(*order).func_idx = i;
			else
				(*order).func_idx = 4;
		}
	}
	if (**fmt == 'i')
	{
		(*order).conv = 'd';
		(*order).func_idx = 2;
	}
}

void	conversion_appropriation(t_order *order)
{
	if ((*order).conv == 'o')
		(*order).base = 8;
	else if ((*order).conv == 'x' || (*order).conv == 'X'
		|| (*order).conv == 'p')
		(*order).base = 16;
	else if ((*order).conv == 'b')
		(*order).base = 2;
	if ((*order).conv == 'f' && (*order).prec == 0)
		(*order).prec = 6;
	else if ((*order).conv == 'f' && (*order).prec == -1)
		(*order).prec = 0;
	if ((*order).conv == 'p')
		(*order).hash = 1;
	if (((*order).conv != 'p' && (*order).conv != 'c' && (*order).conv != 's'
			&& (*order).prec != 0) || ((*order).prec == 0 && (*order).neg == 1))
		(*order).zero = 0;
	if ((*order).prec < -1)
	{
		(*order).mfw = -(*order).prec;
		(*order).neg = 1;
	}
}
