/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:56:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/09 13:58:38 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_t_order(t_order *order)
{
	(*order).space = 0;
	(*order).pos = 0;
	(*order).hash = 0;
	(*order).zero = 0;
	(*order).neg = 0;
	(*order).mfw = 0;
	(*order).prec = 0;
	(*order).flag[0] = 0;
	(*order).flag[1] = 0;
	(*order).conv = 0;
	(*order).base = 10;
	(*order).num_of_padding = 0;
	(*order).num_of_zeros = 0;
	(*order).negative_num = 0;
	(*order).func_idx = -1;
}

void	int_converter(unsigned long long int *u, long long *n, t_order order)
{
	if (n != NULL)
	{
		if (order.flag[0] == 0)
			*n = (int)*n;
		else if (order.flag[1] == 'h')
			*n = (char)*n;
		else if (order.flag[0] == 'h')
			*n = (short)*n;
		else if (order.flag[1] == 'l')
			return ;
		else if (order.flag[0] == 'l')
			*n = (long)*n;
		return ;
	}
	if (order.flag[0] == 0)
		*u = (unsigned int)*u;
	else if (order.flag[1] == 'h')
		*u = (unsigned char)*u;
	else if (order.flag[0] == 'h')
		*u = (unsigned short)*u;
	else if (order.flag[1] == 'l')
		return ;
	else if (order.flag[0] == 'l')
		*u = (unsigned long)*u;
}

void	bundling_bundler(int *length, int (*f)(t_order), t_order *order)
{
	*length += mfw(*length, order, f);
	if ((*order).negative_num)
	{
		write(1, "-", 1);
		*length += 1;
	}
	if ((*order).conv != 's' && (*order).conv != 'c')
		*length += cal_zero(*length, order);
	put_flag((*order).num_of_zeros, '0');
}

int	check_value(unsigned long long u, long long int *n, t_order *order)
{
	if (u == 0)
	{
		if ((*order).hash == 1 && (*order).conv != 'p')
			(*order).hash = -1;
	}
	if (n != NULL && *n < 0)
	{
		(*order).pos = 0;
		(*order).space = 0;
		if (*n < 0 && (*order).conv != 'f')
		{
			(*order).negative_num = 1;
			*n = -*n;
		}
	}
	return (0);
}
