/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:56:51 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/02 14:27:02 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	initialize_t_order(t_order *order)
{
	(*order).mfw = 0;
	(*order).space = 0;
	(*order).hash = 0;
	(*order).zero = 0;
	(*order).neg = 0;
	(*order).pos = 0;
	(*order).prec = 0;
	(*order).conv = 0;
}
