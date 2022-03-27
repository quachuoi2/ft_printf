/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:19:29 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/27 09:43:13 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	put_flag(int ammount, char c, int fd)
{
	while (ammount-- > 0)
		write(fd, &c, 1);
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

void	extra_functionality(char **fmt, char (*default_color)[5], int *fd,
			va_list ap)
{
	char	*color;

	color = NULL;
	if (*(++*fmt) == 'r')
		color = "\x1B[31m";
	else if (**fmt == 'g')
		color = "\x1B[32m";
	else if (**fmt == 'b')
		color = "\x1B[34m";
	else if (**fmt == 'w')
		color = "\x1B[37m";
	else if (**fmt == 'd')
		color = "\x1B[0m";
	else if (**fmt == '0')
		*fd = va_arg(ap, int);
	else
	{
		write(*fd, "$", 1);
		if (**fmt == '$')
			(*fmt)++;
		write(*fd, *fmt, 1);
	}
	if (*default_color && color)
		ft_strcpy(*default_color, color);
	write(*fd, color, 5);
}
