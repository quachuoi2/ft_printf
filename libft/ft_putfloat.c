/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/07 17:46:39 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(long double lift, int i)
{
	ft_putnbr((int)lift);
	if (i > 0)
	{
		lift = ft_abs(lift);
		write(1, ".", 1);
		lift -= (int)lift;
		while (i > 0)
		{
			lift *= 10;
			if (lift == 0)
				write (1, "0", 1);
			i--;
		}
		if (lift != 0)
		{
			if (lift - (int)lift >= 0.5)
				ft_putnbr((int)lift + 1);
			else
				ft_putnbr((int)lift);
		}
	}
}
