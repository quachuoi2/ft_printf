/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:42:47 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/14 04:10:22 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	cs(t_order order, va_list ap)
{
	char		*s;
	char		c;
	int			i;

	if (order.conv == 'c')
	{
		c = va_arg(ap, int);
		i = 1;
		bundling_bundler(&i, NULL, &order);
		write(1, &c, 1);
	}
	else if (order.conv == 's')
	{
		s = va_arg(ap, char *);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		i = ft_strlen(s);
		bundling_bundler(&i, NULL, &order);
		write(1, s, i);
	}
	return (i);
}
