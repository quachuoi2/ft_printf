/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/03/09 14:51:52 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(long double lift, int i)
{
	ft_putnbr((long long int)lift);
	if (i > 0)
	{
		if (lift < 0)
			lift *= -1;
		write(1, ".", 1);
		lift -= (long long int)lift;
		while (i > 0)
		{
			lift *= 10;
			if (lift == 0)
				write (1, "0", 1);
			i--;
		}
		if (lift != 0)
		{
			if (lift - (long long int)lift >= 0.5)
				ft_putnbr((long long int)lift + 1);
			else
				ft_putnbr((long long int)lift);
		}
	}
}
