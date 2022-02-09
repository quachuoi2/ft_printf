/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:17:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/10 01:50:39 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_prefix(char **fmt, t_order *order)
{
	while (!ft_isalpha(**fmt))
	{
		if ((*order).mfw == 0 && (*order).prec == 0)
		{
			(*order).space += (**fmt == ' ');
			(*order).hash += (**fmt == '#');
			(*order).zero += (**fmt == '0');
			(*order).neg += (**fmt == '-');
			(*order).pos += (**fmt == '+');
		}
		if ((**fmt >= '1' && **fmt <= '9') || (*fmt)[-1] == '.')
		{
			if ((*order).mfw == 0)
				(*order).mfw = ft_atoi(*fmt);
			else if ((*order).prec == 0)
				(*order).prec = ft_atoi(*fmt);
			while (ft_isdigit(**fmt))
				(*fmt)++;
			if ((*order).prec || (*fmt)[-1] != '.')
				return ;
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

	ft_strcpy(conv, "cspdiouxXf %");
	i = -1;
	while (conv[++i])
		if (**fmt == conv[i])
			(*order).conv = **fmt;
}
