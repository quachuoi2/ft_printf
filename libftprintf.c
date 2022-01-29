/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/29 09:12:46 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	type_check(char **restrict p_fmt, va_list ap)
{
	char	c;
	int		d;
	char	*s;
	void	*p;

	if (**p_fmt == '%')
	{
		*p_fmt += 1;
		if (**p_fmt == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar(c);
		}
		else if (**p_fmt == 'd')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
		}
		else if (**p_fmt == 'p')
		{
			p = va_arg(ap, void *);
		}
		else if (**p_fmt == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr(s);
		}
		else if (**p_fmt == '%')
			ft_putchar(**p_fmt);
	}
	else
		ft_putchar(**p_fmt);
}

int	ft_printf(const char *restrict fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		type_check((char **)&fmt, ap);
		fmt++;
	}
	va_end(ap);
}
