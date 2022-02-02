/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:17:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/02 15:45:51 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_conv(char *fmt, t_order *order)
{
	char	conv[12];
	char	s;
	int		i;

	ft_strcpy(conv, "cspdiouxXf %");
	while (!ft_isalpha(*fmt))
		fmt++;
	i = 0;
	//checkflags"hh h ll l L"
	while (conv[i])
	{
		if (*fmt == conv[i])
			(*order).conv = *fmt;
		i++;
	}
}

void	check_prefix(char *fmt, t_order *order)
{
	while (*fmt != (*order).conv)
	{
		if ((*order).zero == 0 && (*order).mfw == 0 && (*order).prec == 0)
		{
			if ((*order).conv == 'd' || (*order).conv == 'i' || (*order).conv == 'f')
			{
				if (*fmt == '+')
					(*order).pos = 1;
				else if (*fmt == ' ')
					(*order).space = 1;
			}
			if (*fmt == '#' && ((*order).conv == 'x' || (*order).conv == 'X' || (*order).conv == 'o'))
				(*order).hash = 1;
			else if (*fmt == '-')
				(*order).neg = 1;
			else if (*fmt == '0')
				(*order).zero = 1;
		}
		else if (*fmt >= '1' && *fmt <= '9' && (*order).prec == 0)
			(*order).mfw = (*fmt) - '0';
		else if (*fmt == '.')
			(*order).prec = 999;
		fmt++;
	}
}

void	check_flag(char *fmt, t_order *order)
{
/* 		else if (*fmt == 'h')
	{
		*fmt += 1;
		if (*fmt == 'h')
	}
	else if (*fmt == 'l')
	{
		*fmt += 1;
		if (*fmt == 'l')
	} */
}
