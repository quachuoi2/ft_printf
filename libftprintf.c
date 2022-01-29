/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:49:10 by qnguyen           #+#    #+#             */
/*   Updated: 2022/01/29 11:11:47 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char hex_digit(int v)
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10;
}

void print_address_hex(void* p0)
{
	char		bool;
    int 		i;
    intptr_t 	p;

	p = (intptr_t)p0;
    ft_putchar('0'); ft_putchar('x');
	i = (sizeof(p) << 3) - 4;
	bool = 0;
	while (i >= 0)
	{
		if (!bool && hex_digit((p >> i) & 0b1111) != '0')
			bool = 1;
		else if (bool)
			ft_putchar(hex_digit((p >> i) & 0b1111));
		i -= 4;
	}
}

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
			ft_putchar(va_arg(ap, int));
		else if (**p_fmt == 'd')
			ft_putnbr(va_arg(ap, int));
		else if (**p_fmt == 'p')
			print_address_hex(va_arg(ap, void *));
		else if (**p_fmt == 's')
			ft_putstr(va_arg(ap, char *));
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
