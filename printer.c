/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:42:47 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/06 16:07:48 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	put_c(t_order *order, va_list ap)
{
	char		c;
	int			length;

	c = va_arg(ap, int);
	length = 1;
	bundling_bundler(&length, NULL, order);
	write(1, &c, 1);
	return (length);
}

int	put_s(t_order *order, va_list ap)
{
	char		*s;
	int			length;
	int			str_len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	str_len = ft_strlen(s);
	if ((*order).prec > 0 && (*order).prec < str_len)
		length = (*order).prec;
	else
		length = ft_strlen(s);
	bundling_bundler(&length, NULL, order);
	if ((*order).prec > 0 && (*order).prec < str_len)
		write(1, s, (*order).prec);
	else
		ft_putstr(s);
	return (length);
}

int	put_d(t_order *order, va_list ap)
{
	long long int	n;
	int				length;

	length = 0;
	n = va_arg(ap, long long int);
	int_converter(NULL, &n, *order);
	length += check_value(0, &n, order) + ft_diglen(n);
	bundling_bundler(&length, &spc_pos, order);
	if (n == (long long int)-9223372036854775808u)
	{
		write(1, "9223372036854775808", 19);
		return (length - 1);
	}
	if ((*order).prec == -1 && n == 0)
		return (length - 1);
	ft_putnbr(n);
	return (length);
}

int	put_f(t_order *order, va_list ap)
{
	long double	f;
	int			length;

	length = 0;
	if ((*order).flag[0] == 'L')
		f = va_arg(ap, long double);
	else
		f = va_arg(ap, double);
	length += check_value(0, (long long int *)&f, order)
		+ ft_diglen(f) + (*order).prec + ((*order).prec != 0);
	bundling_bundler(&length, &spc_pos, order);
	ft_putfloat(f, (*order).prec);
	return (length);
}

int	put_pouxx(t_order *order, va_list ap)
{
	int						length;
	unsigned long long int	u;

	length = 0;
	if ((*order).conv == 'p')
		u = (intptr_t)va_arg(ap, void *);
	else
		u = va_arg(ap, unsigned long long int);
	if ((*order).conv != 'p')
		int_converter(&u, 0, *order);
	length += check_value(u, 0, order) + ft_udiglen(u, (*order).base);
	bundling_bundler(&length, &hash, order);
	if (u == 0 && (*order).prec == -1 && (*order).conv != 'p')
		if ((*order).conv != 'o'
			|| ((*order).conv == 'o' && (*order).hash == 0))
			return (length - 1);
	if ((*order).conv != 'p' || u != 0)
		ft_d2base(u, (*order).base, (*order).conv);
	return (length);
}
