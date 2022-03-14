/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:42:06 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/14 21:29:52 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	hash_pos_spc(t_order *order)
{
	if ((*order).hash > 0)
	{
		if ((*order).conv == 'b')
			write(1, "0b", 2);
		else if ((*order).conv == 'X')
			write(1, "0X", 2);
		else if ((*order).conv == 'x' || (*order).conv == 'p')
			write(1, "0x", 2);
		else if ((*order).conv == 'o')
			write(1, "0", 1);
		return (2 - ((*order).conv == 'o'));
	}
	if ((*order).pos && (*order).conv == 'd')
		write(1, "+", 1);
	else if ((*order).space && (*order).conv == 'd')
		write(1, " ", 1);
	return (((*order).pos || (*order).space) * ((*order).conv == 'd'));
}

int	cal_zero(int length, t_order *order)
{
	int	zero;

	if ((*order).num_of_zeros != 0)
		return (0);
	zero = 0;
	if ((*order).prec == 0)
	{
		zero = (*order).mfw - ((*order).pos || (*order).space)
			- length - (*order).negative_num;
		if ((*order).hash == 1 && (*order).conv == 'o')
			zero -= 1;
		else if ((*order).hash == 1)
			zero -= 2;
	}
	else
	{
		if ((*order).mfw > (*order).prec)
			zero = (*order).mfw - length;
		else
			zero = (*order).prec - length;
	}
	(*order).num_of_zeros = (zero > 0) * zero;
	return ((*order).num_of_zeros);
}

int	cal_padding(int length, t_order *order)
{
	int	padding;

	padding = 0;
	padding = (*order).mfw - ((*order).pos || (*order).space)
		- length - (*order).negative_num;
	if ((*order).prec > length && (*order).conv != 's')
		padding -= (*order).prec - length;
	if ((*order).hash == 1 && (*order).conv == 'o')
		padding -= 1;
	else if ((*order).hash == 1)
		padding -= 2;
	(*order).num_of_padding = (padding > 0) * padding;
	return ((*order).num_of_padding);
}

int	mfw(int length, t_order *order, int (*f)(t_order *))
{
	int	i;

	i = 0;
	if (length < (*order).mfw || length < (*order).prec)
	{
		if (((*order).zero || (*order).mfw < (*order).prec)
			&& (*order).conv != 's' && (*order).conv != 'c')
		{
			if (f)
				i += f((order));
			if ((*order).conv == 'o')
				length += i;
			i += cal_zero(length, order);
			return (i);
		}
		i += cal_padding(length, order);
		if ((*order).neg == 0)
			put_flag((*order).num_of_padding, ' ');
	}
	if (f)
		i += f((order));
	return (i);
}
