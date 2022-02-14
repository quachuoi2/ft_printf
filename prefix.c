/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:17:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 03:47:01 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_prefix(char **fmt, t_order *order)
{
	while (ft_isacceptable(**fmt))
	{
		if ((*order).mfw == 0 && (*order).prec == 0)
		{
			(*order).space += (**fmt == ' ');
			(*order).hash += (**fmt == '#');
			(*order).zero += (**fmt == '0');
			(*order).neg += (**fmt == '-');
			(*order).pos += (**fmt == '+');
		}
		if ((**fmt >= '1' && **fmt <= '9') || **fmt == '.')
		{
			if (**fmt != '.')
				(*order).mfw = ft_atoi(*fmt);
			else
			{
				(*fmt)++;
				if (!ft_atoi(*fmt))
					(*order).prec = -1;
				else
					(*order).prec = ft_atoi(*fmt);
			}
			while (ft_isdigit(**fmt))
				(*fmt)++;
			if (**fmt != '.')
				return ;
			(*fmt)--;
		}
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
	char	conv[12];
	int		i;

	ft_strcpy(conv, "cspdiouxXf %\0");
	i = 0;
	while (conv[i])
	{
		if (**fmt == conv[i])
			(*order).conv = **fmt;
		i++;
	}
	if (**fmt == 'o')
		(*order).base = 8;
	else if (**fmt == 'x' || **fmt == 'X' || **fmt == 'p')
		(*order).base = 16;
	if (**fmt == 'f' && (*order).prec == 0)
		(*order).prec = 6;
	else if ((*order).prec == -1)
		(*order).prec = 0;
}
